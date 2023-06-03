#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct Account_ {
  double balance;
} Account;

void Account_Init(Account* self);

double Account_GetBalance(const Account* self);
void Account_Deposit(Account* self, double amount);
double Account_Withdraw(Account* self, double amount);
double Account_CalculateInterest(const Account* self);

#endif  // ACCOUNT_H
