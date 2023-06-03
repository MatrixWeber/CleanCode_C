#include "account.h"
#include <stdio.h>

static void Account_WriteLog(const char* message, double data);

void Account_Init(Account* self) { self->balance = 0.0; }

double Account_GetBalance(const Account* self) { return self->balance; }

void Account_Deposit(Account* self, double amount)
{
  self->balance += amount;
  Account_WriteLog("\nDeposit, amount: ", amount);
}

double Account_Withdraw(Account* self, double amount)
{
  self->balance -= amount;

  Account_WriteLog("\nWithdraw, amount: ", amount);
  return amount;
}

double Account_CalculateInterest(const Account* self)
{
  return self->balance * 0.001;
}

void Account_WriteLog(const char* message, double data)
{
  FILE* file = fopen("logfile.txt", "a");
  fprintf(file, "%s %f\n", message, data);
  fclose(file);
}
