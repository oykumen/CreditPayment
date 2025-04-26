#pragma once

namespace CreditPayment {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_calculate;
	private: System::Windows::Forms::GroupBox^ GroupBox_Payment;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox_Percent;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_Term;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_Sum;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button_Write;
	private: System::Windows::Forms::GroupBox^ groupBox_Write;
	private: System::Windows::Forms::TextBox^ textBox_FileName;
	private: System::Windows::Forms::CheckBox^ checkBox_appFile;
	private: System::Windows::Forms::GroupBox^ groupBox_OverPayment;

	private: System::Windows::Forms::Button^ button_calculateOverPayment;

	private: System::Windows::Forms::TextBox^ textBox_FileNameOverPayment;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_OverPayment;















	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_calculate = (gcnew System::Windows::Forms::Button());
			this->GroupBox_Payment = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_Percent = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_Term = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_Sum = (gcnew System::Windows::Forms::TextBox());
			this->button_Write = (gcnew System::Windows::Forms::Button());
			this->groupBox_Write = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_appFile = (gcnew System::Windows::Forms::CheckBox());
			this->textBox_FileName = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_OverPayment = (gcnew System::Windows::Forms::GroupBox());
			this->button_calculateOverPayment = (gcnew System::Windows::Forms::Button());
			this->textBox_FileNameOverPayment = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog_OverPayment = (gcnew System::Windows::Forms::OpenFileDialog());
			this->GroupBox_Payment->SuspendLayout();
			this->groupBox_Write->SuspendLayout();
			this->groupBox_OverPayment->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_calculate
			// 
			this->button_calculate->Location = System::Drawing::Point(266, 199);
			this->button_calculate->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_calculate->Name = L"button_calculate";
			this->button_calculate->Size = System::Drawing::Size(150, 47);
			this->button_calculate->TabIndex = 0;
			this->button_calculate->Text = L"Рассчитать";
			this->button_calculate->UseVisualStyleBackColor = true;
			this->button_calculate->Click += gcnew System::EventHandler(this, &MyForm::button_calculate_Click);
			// 
			// GroupBox_Payment
			// 
			this->GroupBox_Payment->Controls->Add(this->label6);
			this->GroupBox_Payment->Controls->Add(this->label5);
			this->GroupBox_Payment->Controls->Add(this->label4);
			this->GroupBox_Payment->Controls->Add(this->label3);
			this->GroupBox_Payment->Controls->Add(this->button_calculate);
			this->GroupBox_Payment->Controls->Add(this->textBox_Percent);
			this->GroupBox_Payment->Controls->Add(this->label2);
			this->GroupBox_Payment->Controls->Add(this->textBox_Term);
			this->GroupBox_Payment->Controls->Add(this->label1);
			this->GroupBox_Payment->Controls->Add(this->textBox_Sum);
			this->GroupBox_Payment->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GroupBox_Payment->Location = System::Drawing::Point(20, 21);
			this->GroupBox_Payment->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->GroupBox_Payment->Name = L"GroupBox_Payment";
			this->GroupBox_Payment->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->GroupBox_Payment->Size = System::Drawing::Size(492, 255);
			this->GroupBox_Payment->TabIndex = 1;
			this->GroupBox_Payment->TabStop = false;
			this->GroupBox_Payment->Text = L"Расчёт ежемесячного платежа";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(422, 153);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 28);
			this->label6->TabIndex = 8;
			this->label6->Text = L"%";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(422, 99);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 28);
			this->label5->TabIndex = 7;
			this->label5->Text = L"м.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(424, 47);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 28);
			this->label4->TabIndex = 6;
			this->label4->Text = L"руб.";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 153);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(187, 28);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Процентная ставка";
			// 
			// textBox_Percent
			// 
			this->textBox_Percent->Location = System::Drawing::Point(266, 149);
			this->textBox_Percent->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_Percent->Name = L"textBox_Percent";
			this->textBox_Percent->Size = System::Drawing::Size(148, 34);
			this->textBox_Percent->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 99);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(136, 28);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Срок кредита";
			// 
			// textBox_Term
			// 
			this->textBox_Term->Location = System::Drawing::Point(266, 94);
			this->textBox_Term->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_Term->Name = L"textBox_Term";
			this->textBox_Term->Size = System::Drawing::Size(148, 34);
			this->textBox_Term->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 47);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 28);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Сумма кредита";
			// 
			// textBox_Sum
			// 
			this->textBox_Sum->Location = System::Drawing::Point(266, 42);
			this->textBox_Sum->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_Sum->Name = L"textBox_Sum";
			this->textBox_Sum->Size = System::Drawing::Size(148, 34);
			this->textBox_Sum->TabIndex = 0;
			// 
			// button_Write
			// 
			this->button_Write->Enabled = false;
			this->button_Write->Location = System::Drawing::Point(327, 28);
			this->button_Write->Name = L"button_Write";
			this->button_Write->Size = System::Drawing::Size(75, 29);
			this->button_Write->TabIndex = 2;
			this->button_Write->Text = L"Запись";
			this->button_Write->UseVisualStyleBackColor = true;
			this->button_Write->Click += gcnew System::EventHandler(this, &MyForm::button_Write_Click);
			// 
			// groupBox_Write
			// 
			this->groupBox_Write->Controls->Add(this->checkBox_appFile);
			this->groupBox_Write->Controls->Add(this->textBox_FileName);
			this->groupBox_Write->Controls->Add(this->button_Write);
			this->groupBox_Write->Location = System::Drawing::Point(519, 21);
			this->groupBox_Write->Name = L"groupBox_Write";
			this->groupBox_Write->Size = System::Drawing::Size(408, 100);
			this->groupBox_Write->TabIndex = 3;
			this->groupBox_Write->TabStop = false;
			this->groupBox_Write->Text = L"Запись графика платежей в файл";
			// 
			// checkBox_appFile
			// 
			this->checkBox_appFile->AutoSize = true;
			this->checkBox_appFile->Location = System::Drawing::Point(296, 63);
			this->checkBox_appFile->Name = L"checkBox_appFile";
			this->checkBox_appFile->Size = System::Drawing::Size(121, 32);
			this->checkBox_appFile->TabIndex = 4;
			this->checkBox_appFile->Text = L"Дописать";
			this->checkBox_appFile->UseVisualStyleBackColor = true;
			// 
			// textBox_FileName
			// 
			this->textBox_FileName->Location = System::Drawing::Point(6, 28);
			this->textBox_FileName->Name = L"textBox_FileName";
			this->textBox_FileName->Size = System::Drawing::Size(315, 34);
			this->textBox_FileName->TabIndex = 3;
			// 
			// groupBox_OverPayment
			// 
			this->groupBox_OverPayment->Controls->Add(this->button_calculateOverPayment);
			this->groupBox_OverPayment->Controls->Add(this->textBox_FileNameOverPayment);
			this->groupBox_OverPayment->Location = System::Drawing::Point(519, 127);
			this->groupBox_OverPayment->Name = L"groupBox_OverPayment";
			this->groupBox_OverPayment->Size = System::Drawing::Size(408, 149);
			this->groupBox_OverPayment->TabIndex = 4;
			this->groupBox_OverPayment->TabStop = false;
			this->groupBox_OverPayment->Text = L"Рассчитать переплату по файлу";
			// 
			// button_calculateOverPayment
			// 
			this->button_calculateOverPayment->Enabled = false;
			this->button_calculateOverPayment->Location = System::Drawing::Point(296, 74);
			this->button_calculateOverPayment->Name = L"button_calculateOverPayment";
			this->button_calculateOverPayment->Size = System::Drawing::Size(106, 29);
			this->button_calculateOverPayment->TabIndex = 6;
			this->button_calculateOverPayment->Text = L"Рассчитать";
			this->button_calculateOverPayment->UseVisualStyleBackColor = true;
			this->button_calculateOverPayment->Click += gcnew System::EventHandler(this, &MyForm::button_calculateOverPayment_Click);
			// 
			// textBox_FileNameOverPayment
			// 
			this->textBox_FileNameOverPayment->Location = System::Drawing::Point(6, 39);
			this->textBox_FileNameOverPayment->Name = L"textBox_FileNameOverPayment";
			this->textBox_FileNameOverPayment->Size = System::Drawing::Size(396, 34);
			this->textBox_FileNameOverPayment->TabIndex = 0;
			this->textBox_FileNameOverPayment->Text = L"Выберите файл";
			this->textBox_FileNameOverPayment->Click += gcnew System::EventHandler(this, &MyForm::textBox_FileNameOverPayment_Click);
			// 
			// openFileDialog_OverPayment
			// 
			this->openFileDialog_OverPayment->FileName = L"openFileDialog1";
			this->openFileDialog_OverPayment->Filter = L"Текстовые файлы | *.txt";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 28);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(939, 288);
			this->Controls->Add(this->groupBox_OverPayment);
			this->Controls->Add(this->groupBox_Write);
			this->Controls->Add(this->GroupBox_Payment);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Кредитный платёж";
			this->GroupBox_Payment->ResumeLayout(false);
			this->GroupBox_Payment->PerformLayout();
			this->groupBox_Write->ResumeLayout(false);
			this->groupBox_Write->PerformLayout();
			this->groupBox_OverPayment->ResumeLayout(false);
			this->groupBox_OverPayment->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_calculate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Write_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Boolean check_data();
	private: System::Void textBox_FileNameOverPayment_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_calculateOverPayment_Click(System::Object^ sender, System::EventArgs^ e);
};
}
