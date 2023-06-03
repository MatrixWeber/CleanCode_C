#include "account.h"
#include <stddef.h>
#include "logger.h"

void Account_Init(Account* self)
{
  self->balance = 0.0;
  self->interest_calculator = NULL;
}

double Account_GetBalance(Account* self) { return self->balance; }

void Account_SetInterestCalculator(
    Account* self, InterestCalculatorFunction interest_calculator)
{
  self->interest_calculator = interest_calculator;
}

void Account_Deposit(Account* self, double amount)
{
  self->balance += amount;

  LogDouble("\nDeposit, balance: ", self->balance);
}

double Account_Withdraw(Account* self, double amount)
{
  self->balance -= amount;

  LogDouble("\nWithdraw, balance: ", self->balance);

  return amount;
}

double Account_CalculateInterest(Account* self)
{
  if (self->interest_calculator == NULL) {
    return 0.0;
  }

  const double interest = self->interest_calculator(self->balance);

  LogDouble("\nCalculate interest, amount: ", interest);

  return interest;
}
