#include "account.h"

void Account_Init(Account *const self, const int id)
{
  self->balance = 0.0;
  self->id = id;
}

double Account_GetBalance(Account *const self) { return self->balance; }

void Account_SetBalance(Account *const self, const double balance)
{
  self->balance = balance;
}

void Account_ChangeBalance(Account *const self, const double amount)
{
  self->balance += amount;
}

int Account_GetId(Account *const self) { return self->id; }
