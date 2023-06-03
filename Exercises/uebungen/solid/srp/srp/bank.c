#include "bank.h"
#include <stdio.h>
#include <time.h>
#include "account.h"

static void Bank_WriteLog(const char* message, double data);
static void Bank_WriteLog_S(const char* message, const char* info);

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
      Bank_WriteLog("\nDeposit, balance:",
                    Account_GetBalance(self->accounts[i]));
    }
  }

  time_t current_time;
  time(&current_time);

  const char* time_string = ctime(&current_time);
  Bank_WriteLog_S("\nInterest paid on: ", time_string);
}

void Bank_WriteLog(const char* message, double data)
{
  FILE* file = fopen("logfile.txt", "a");
  fprintf(file, "%s %f\n", message, data);
  fclose(file);
}

static void Bank_WriteLog_S(const char* message, const char* info)
{
  FILE* file = fopen("logfile.txt", "a");
  fprintf(file, "%s %s\n", message, info);
  fclose(file);
}
