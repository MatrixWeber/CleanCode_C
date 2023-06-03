#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct Account_ {
  double balance;
  int id;
} Account;

void Account_Init(Account* self, const int id);

double Account_GetBalance(Account* self);
void Account_SetBalance(Account* self, const double balance);
int Account_GetId(Account* self);

#endif  // ACCOUNT_H
