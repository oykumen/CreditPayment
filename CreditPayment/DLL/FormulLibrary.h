#pragma once

#ifdef FORMULLIBRARY_EXPORTS
#define FORMULLIBRARY_API __declspec(dllexport)
#else
#define FORMULLIBRARY_API __declspec(dllimport)
#endif

extern "C" FORMULLIBRARY_API float annuity_payment(int S, short N, float P);

extern "C" FORMULLIBRARY_API float credit_percent(int Sn, float P);