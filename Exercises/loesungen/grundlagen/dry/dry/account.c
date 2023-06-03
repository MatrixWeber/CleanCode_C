#include "account.h"

void Account_Init(Account* self, const int id)
{
  self->balance = 0.0;
  self->id = id;
}

double Account_GetBalance(const Account* self) { return self->balance; }

void Account_SetBalance(Account* self, const double balance)
{
  self->balance = balance;
}

int Account_GetId(const Account* self) { return self->id; }
