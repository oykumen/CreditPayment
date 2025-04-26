#include "MyForm.h"
#include <cmath>
#include "FormulLibrary.h"
#include <thread>
#include <mutex>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <iostream>
#include <iomanip>

#include <chrono>

using namespace System;
using namespace System::Windows::Forms;
std::thread th_write;
[STAThreadAttribute]

int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::VisualStyleState;
	
	CreditPayment::MyForm form;
	Application::Run(% form);
}

int S = 0; // ����� �������
short N = 0; // ���� �������
float P = 0; // ������� �������
float payment = 0; // ����������� �������
bool appFile = false; // �������� � ����/������� �����


//std::mutex mtx;
// ������� ��� ���������� ��������� 
int OverPayment(std::string filename)
{
	int S_OverPay = 0;
	short N_OverPay = 0, i = 0;

	float Payment_OverPay = 0, last_Payment_OverPay = 0;
	std::string line, buf;
	std::ifstream in;
	in.open(filename);
	if (!in.is_open())
		return -1;
	try {
		while (std::getline(in, line))
		{
			if (line[0] == '_')
			{
				i++;
				continue;
			}
			if (i == 2) break;
			if (line[2] == '�') continue;
			if (S_OverPay == 0) {
				buf = line.substr(1, 26);
				S_OverPay = stoi(buf);
				buf.clear();
				buf = line.substr(27, 19);
				Payment_OverPay = stof(buf);
			}
			buf = line.substr(27, 19);
			last_Payment_OverPay = stof(buf);
			N_OverPay++;
		}
	}
	catch (...)
	{
		return -1;
	}

	in.close();
	return (N_OverPay-1) * Payment_OverPay + last_Payment_OverPay - S_OverPay;
}
// ������� ��� �������� �������� ����������
System::Boolean CreditPayment::MyForm::check_data(){
	String^ text_S = textBox_Sum->Text;
	String^ text_N = textBox_Term->Text;
	String^ text_P = textBox_Percent->Text;

	try {
		S = Convert::ToInt32(text_S);
		N = Convert::ToInt16(text_N);
		P = Convert::ToDouble(text_P);
	}
	catch (...) {
		return false;
	}
	return true;
}
// ����� ����������� ���� ��� ������ �����
System::Void CreditPayment::MyForm::textBox_FileNameOverPayment_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ FileName;
	
	/*if (openFileDialog_OverPayment->ShowDialog() != DialogResult::OK)
		return;
	*/

	openFileDialog_OverPayment->ShowDialog();

	try
	{
		FileName = openFileDialog_OverPayment->FileName;
	}
	catch(...)
	{ 
		MessageBox::Show("������ ������ ������� �����!", "������!"); 
		return;
	}
	if (FileName == "openFileDialog1")
	{
		MessageBox::Show("���� �� ������!", "������!");
		return;
	}
	textBox_FileNameOverPayment->Text = FileName;

	button_calculateOverPayment->Enabled = true;

	return System::Void();
}
// ������� ������ ��� ���������� ���������
System::Void CreditPayment::MyForm::button_calculateOverPayment_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string filename = msclr::interop::marshal_as<std::string>(textBox_FileNameOverPayment->Text);

	int OverPay = OverPayment(filename);

	if (OverPay == -1)
	{
		MessageBox::Show("���� �� ������������� ����������� ���� ��������!","������ �������� �����!");
		button_calculateOverPayment->Enabled = false;
	}
	else
	{
		MessageBox::Show("��������� ����� = " + Convert::ToString(OverPay), "���������");
	}
	return System::Void();
}
// ������� ������ ��� ���������� ������������ �������
System::Void CreditPayment::MyForm::button_calculate_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!check_data())
	{
		MessageBox::Show("������� ������������ ��������!", "������!");
		return;
	}

	payment = annuity_payment(S, N, P);

	if (payment == -1)
	{
		MessageBox::Show("������� ������������� ����������!","������!");
		return;
	}

	payment = round(payment * 100) / 100;

	String^ txt = Convert::ToString(payment);

	MessageBox::Show(txt + " ���. � �����", "����������� �����");

	button_Write->Enabled = true;

	return System::Void();
}
// �������� ����� ����� �� ������������
bool check_filename(String^ name)
{
	for (int i = 0; i < name->Length; i++)
	{
		if (name[i] == '/' || name[i] == 92 || name[i] == ':' || name[i] == '?' ||
			name[i] == '"' || name[i] == '<' || name[i] == '>' || name[i] == '|' ||
			name[i] == '+' || name[i] == '.' || name[i] == ' ')
		{
			return false;
		}
	}
	return true;
}
// ������� ��� ������ � ���� ������� ��������
void write_schedule(std::string filename)
{
	
	//std::lock_guard<std::mutex> LG(mtx);
	std::ofstream out;
	if (appFile) {
			out.open(filename, std::ios::app);
	}
	else
	{
		out.open(filename, std::ios::out);
	}
	int Sn = S;
	// ����� ���������� �������� ��� �����
	//out << System::Diagnostics::Process::GetCurrentProcess()->Threads->Count;
	if (out.is_open())
	{
		out << std::setw(87) << std::setfill('_') << "\n"
			<< std::setfill(' ')
			<< std::setw(27) << "| ������� ��������� ����� |"
			<< std::setw(20) << " ����������� ����� |"
			<< std::setw(22) << " ��������� ��������� |"
			<< std::setw(18) << " ��������� ����� |" << "\n";
	}
	// ����� ����������� ���������� � ��������
	while (Sn > payment)
	{
		float percents = credit_percent(Sn, P);
		out << "| " << std::setw(23) << Sn << " |"
			<< std::setw(18) << payment << " |"
			<< std::setw(20) << percents << " |"
			<< std::setw(16) << payment - percents << " |" << "\n";
		Sn = Sn - (payment - percents);
		std::this_thread::sleep_for(std::chrono::milliseconds(120));
	}
	// ����� ������ �� ��������� �����
	out << "| " << std::setw(23) << Sn << " |"
		<< std::setw(18) << Sn << " |"
		<< std::setw(20) << credit_percent(Sn, P) << " |"
		<< std::setw(16) << Sn - credit_percent(Sn, P) << " |" << "\n";
	Sn = 0;
	out.close();
	
	th_write.detach();
}
// ������� ������ ��� ������ ������� � ����
System::Void CreditPayment::MyForm::button_Write_Click(System::Object^ sender, System::EventArgs^ e)
{
	appFile = checkBox_appFile->Checked;
	String^ filename = textBox_FileName->Text;
	if (filename == "")
	{
		MessageBox::Show("������� �������� �����!", "������!");
		return;
	}
	if (!check_filename(filename))
	{
		MessageBox::Show("������� ������������ �������� �����!", "������!");
		return;
	}
	filename = "Credits/" + filename + ".txt";
	// �������� �� ������������� �����
	if (System::IO::File::Exists(filename) && !appFile)
	{
		MessageBox::Show("������ ���� ��� ����������!\n�������� ��������, ���� ������ �������� ������ � ����!", "������!");
		return;
	}
	if (!System::IO::File::Exists(filename) && appFile)
	{
		MessageBox::Show("������ ���� ����������!\n������� ������� ��������, ���� ������ ������� ����� ����!", "������!");
		return;
	}
	
	std::string name = msclr::interop::marshal_as<std::string>(filename); // String^ to std::string

	
	button_Write->Enabled = false;

	
	th_write = std::thread(write_schedule, name);

	return System::Void();	
}



