#include "bank.h"
#include <stdio.h>
#include "account.h"
#include "logging.h"

void Bank_Init(Bank* self)
{
  for (int i = 0; i < MAX_ACCOUNTS; ++i) {
    Account_Init(&self->account_objects[i]);
  }

  for (int i = 0; i < MAX_ACCOUNTS; ++i) {
    self->accounts[i] = NULL;
  }
}

Account* Bank_CreateAccount(Bank* self)
{
  int account_index = -1;
  for (int i = 0; i < MAX_ACCOUNTS; ++i) {
    if (self->accounts[i] == NULL) {
      self->accounts[i] = &self->account_objects[i];
      account_index = i;
      break;
    }
  }

  if (account_index < 0) {
    printf("Account cannot be created.\n");
    return NULL;
  }

  Account* account = &self->account_objects[account_index];
  return account;
}

void Bank_PayInterest(Bank* self)
{
  for (int i = 0; i < MAX_ACCOUNTS; ++i) {
    if (self->accounts[i] != NULL) {
      const double interest = Account_CalculateInterest(self->accounts[i]);
      Account_Deposit(self->accounts[i], interest);
      WriteLog("\nDeposit, balance:", Account_GetBalance(self->accounts[i]));
    }
  }

  WriteLog_Date("\nInterest paid on: ");
}
