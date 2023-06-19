#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
  double balance;
} Account;

void Account_Init(Account *const self);

double Account_GetBalance(const Account *const self);
void Account_Deposit(Account *const self, const double amount);
double Account_Withdraw(Account *const self, const double amount);
double Account_CalculateInterest(const Account *const self);

#endif  // ACCOUNT_H
