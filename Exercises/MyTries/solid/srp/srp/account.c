#include "account.h"
#include "logger.h"
#include <stdio.h>

void Account_Init(Account* self) { self->balance = 0.0; }

double Account_GetBalance(const Account* self) { return self->balance; }

void Account_Deposit(Account* self, double amount)
{
  self->balance += amount;
  WriteLog("\nDeposit, amount: ", amount);
}

double Account_Withdraw(Account* self, double amount)
{
  self->balance -= amount;

  WriteLog("\nWithdraw, amount: ", amount);
  return amount;
}

double Account_CalculateInterest(const Account* self)
{
  return self->balance * 0.001;
}

