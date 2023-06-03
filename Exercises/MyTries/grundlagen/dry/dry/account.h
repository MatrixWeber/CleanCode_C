#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct Account_ {
  double balance;
  int id;
} Account;

void Account_Init(Account *const self, const int id);

double Account_GetBalance(Account *const self);
void Account_SetBalance(Account *const self, const double balance);
int Account_GetId(Account *const self);
void Account_ChangeBalance(Account *const self, const double amount);

#endif  // ACCOUNT_H
