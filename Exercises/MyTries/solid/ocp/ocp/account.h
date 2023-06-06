#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "account_type.h"
#include "interest_calculator.h"

typedef struct Account_ {
  double balance;
  InterestCalculator* interest_calculator;
} Account;

void Account_Init(Account *self);
double Account_GetBalance(Account* self);

void Account_SetInterest(Account* self, InterestCalculator *const interest_calculator);
void Account_Deposit(Account* self, double amount);
double Account_Withdraw(Account* self, double amount);
double Account_CalculateInterest(Account* self);

#endif  // ACCOUNT_H
