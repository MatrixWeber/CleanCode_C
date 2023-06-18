#include "bank.h"

#include <stddef.h>
#include <stdio.h>

#include "account.h"
#include "tools.h"

#define MAX_STRING_SIZE 256

// private function declarations ...
void Bank_ReportInformationRaw(FILE* file, const char* text, const int account_id);
void Bank_ReportToFile(const char* text, const char* file_name,  const int account_id);
void Bank_ReportToConsole(const char* text);
void Bank_ReportInformation(const char* text, const int account_id);
void Bank_ReportBalanceRaw(const char* text, const Account* account);
void Bank_ReportBalance(const Account* account);
void Bank_ReportBalanceProcess(const char* process, const double amount, const Account* account);
void Bank_ChangeBalance(Account* account, const double amount);
Account* Bank_ReadAccount(Bank* self);

// implementation ...
void Bank_Init(Bank* self)
{
  for (int i = 0; i < MAX_ACCOUNTS; ++i) {
    Account_Init(&self->account_objects[i], i + 1);
  }

  for (int i = 0; i < MAX_ACCOUNTS; ++i) {
    self->accounts[i] = NULL;
  }
}

void Bank_CreateAccount(Bank* self)
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
    return;
  }

  Account* account = &self->account_objects[account_index];

  char output_text[MAX_STRING_SIZE];
  sprintf(output_text, "Account %d created.\n", Account_GetId(account));
  Bank_ReportInformation(output_text, Account_GetId(account));
}

void Bank_Deposit(Bank* self)
{
  Account* account = Bank_ReadAccount(self);
  if (account == NULL) {
    return;
  }

  const double amount = ReadDouble("Enter the amount");
  Bank_ChangeBalance(account, amount);
  Bank_ReportBalanceProcess("deposited", amount, account);
}

void Bank_Withdraw(Bank* self)
{
  Account* account = Bank_ReadAccount(self);
  if (account == NULL) {
    return;
  }

  const double amount = ReadDouble("Enter the amount");
  Bank_ChangeBalance(account, -amount);
  Bank_ReportBalanceProcess("paid", amount, account);
}

void Bank_ShowBalance(Bank* self)
{
  Account* account = Bank_ReadAccount(self);
  if (account == NULL) {
    return;
  }

  Bank_ReportBalance(account);
}

void Bank_ChangeBalance(Account* account, const double amount)
{
  double balance = Account_GetBalance(account);
  balance += amount;
  Account_SetBalance(account, balance);
}

Account* Bank_ReadAccount(Bank* self)
{
  const int account_id = ReadInteger("Please enter your Account number");

  const int account_index = account_id - 1;
  if (account_index >= 0 && account_index < MAX_ACCOUNTS) {
    Account* account = self->accounts[account_index];
    if (account != NULL) {
      return account;
    }
  }

  printf("Account number %d does not exist!\n\n", account_id);
  return NULL;
}

void Bank_ReportBalanceProcess(const char* process, const double amount,
                               const Account* account)
{
  char output_text[MAX_STRING_SIZE];
  sprintf(output_text, "%.02f EUR %s.\n", amount, process);

  Bank_ReportBalanceRaw(output_text, account);
}

void Bank_ReportBalance(const Account* account)
{
  Bank_ReportBalanceRaw("", account);
}

void Bank_ReportBalanceRaw(const char* text, const Account* account)
{
  char output_text[MAX_STRING_SIZE];
  sprintf(output_text, "%sBalance: %.02f EUR.\n", text,
          Account_GetBalance(account));
  Bank_ReportInformation(output_text, Account_GetId(account));
}

void Bank_ReportInformation(const char* text, const int account_id)
{
  char customer_receipt[MAX_STRING_SIZE];
  sprintf(customer_receipt, "customer_receipt_%d.txt", account_id);

  Bank_ReportToConsole(text);
  Bank_ReportToFile(text, customer_receipt, -1);
  Bank_ReportToFile(text, "customer_receipt.txt", account_id);
}

void Bank_ReportToConsole(const char* text)
{
  Bank_ReportInformationRaw(stdout, text, -1);
}

void Bank_ReportToFile(const char* text, const char* file_name,
                       const int account_id)
{
  FILE* file = fopen(file_name, "a");
  Bank_ReportInformationRaw(file, text, account_id);
  fclose(file);
}

void Bank_ReportInformationRaw(FILE* file, const char* text,
                               const int account_id)
{
  if (account_id >= 0) {
    fprintf(file, "Account %d:\n", account_id);
  }

  fprintf(file, "%s\n\n", text);
}
