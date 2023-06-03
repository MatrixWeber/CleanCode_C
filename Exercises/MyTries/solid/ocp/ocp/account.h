#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "account_type.h"

typedef struct Account_ {
  double balance;
  AccountType type;
} Account;

void Account_Init(Account* self);
double Account_GetBalance(Account* self);
AccountType Account_GetType(Account* self);
void Account_SetType(Account* self, AccountType type);
void Account_Deposit(Account* self, double amount);
double Account_Withdraw(Account* self, double amount);
double Account_CalculateInterest(Account* self);

#endif  // ACCOUNT_H
