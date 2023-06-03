#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct Account_ {
  double balance;
  int id;
} Account;

void Account_Init(Account* self, const int id);

double Account_GetBalance(const Account* self);
void Account_SetBalance(Account* self, const double balance);
int Account_GetId(const Account* self);

#endif  // ACCOUNT_H
