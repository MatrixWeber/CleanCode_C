#include "bank.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "account.h"

#define MAX_STRING_SIZE 256

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
  printf("Account %d created.\n", Account_GetId(account));

  char customer_receipt[MAX_STRING_SIZE];
  sprintf(customer_receipt, "customer_receipt_%d.txt", Account_GetId(account));
  const char* bank_receipt = "customer_receipt.txt";

  FILE* customer_receipt_file = fopen(customer_receipt, "a");
  fprintf(customer_receipt_file, "Account %d created.\n\n",
          Account_GetId(account));
  fclose(customer_receipt_file);

  FILE* bank_receipt_file = fopen(bank_receipt, "a");
  fprintf(bank_receipt_file, "Account %d:\n", Account_GetId(account));
  fprintf(bank_receipt_file, "Account %d created.\n\n", Account_GetId(account));
  fclose(bank_receipt_file);
}

void Bank_Deposit(Bank* self)
{
  printf("Please enter your Account number: ");

  int account_id = 0;
  while (true) {
    const int items = scanf("%d", &account_id);

    if (items > 0) {
      break;
    }

    printf("Please enter a number\n");
    char temp;
    while ((temp = fgetc(stdin)) != EOF) {
      if (temp == '\n') {
        break;
      }
    }
  }

  const int account_index = account_id - 1;
  if (account_index < 0 || account_index > MAX_ACCOUNTS) {
    printf("Account number %d does not exist!\n\n", account_id);
    return;
  }

  Account* account = self->accounts[account_index];
  if (account == NULL) {
    printf("Account number %d does not exist!\n\n", account_id);
    return;
  }

  printf("Enter the amount: ");
  double amount;
  while (true) {
    const int items = scanf("%lf", &amount);

    if (items > 0) {
      break;
    }

    printf("Please enter a number\n");
    char temp;
    while ((temp = fgetc(stdin)) != EOF) {
      if (temp == '\n') {
        break;
      }
    }
  }

  double balance = Account_GetBalance(account);
  balance += amount;
  Account_SetBalance(account, balance);

  printf("%f EUR deposited.\n", amount);
  printf("Balance: %f EUR.\n\n", Account_GetBalance(account));

  char customer_receipt[MAX_STRING_SIZE];
  sprintf(customer_receipt, "customer_receipt_%d.txt", Account_GetId(account));
  const char* bank_receipt = "customer_receipt.txt";

  FILE* customer_receipt_file = fopen(customer_receipt, "a");
  fprintf(customer_receipt_file, "%f EUR deposited.\n", amount);
  fprintf(customer_receipt_file, "Balance: %f EUR.\n\n",
          Account_GetBalance(account));
  fclose(customer_receipt_file);

  FILE* bank_receipt_file = fopen(bank_receipt, "a");
  fprintf(bank_receipt_file, "Account %d:\n", Account_GetId(account));
  fprintf(bank_receipt_file, "%f EUR deposited.\n", amount);
  fprintf(bank_receipt_file, "Balance: %f EUR.\n\n",
          Account_GetBalance(account));
  fclose(bank_receipt_file);
}

void Bank_Withdraw(Bank* self)
{
  printf("Please enter your Account number: ");

  int account_id = 0;
  while (true) {
    const int items = scanf("%d", &account_id);

    if (items > 0) {
      break;
    }

    printf("Please enter a number\n");
    char temp;
    while ((temp = fgetc(stdin)) != EOF) {
      if (temp == '\n') {
        break;
      }
    }
  }

  const int account_index = account_id - 1;
  if (account_index < 0 || account_index > MAX_ACCOUNTS) {
    printf("Account number %d does not exist!\n\n", account_id);
    return;
  }

  Account* account = self->accounts[account_index];
  if (account == NULL) {
    printf("Account number %d does not exist!\n\n", account_id);
    return;
  }

  printf("Enter the amount: ");
  double amount;
  while (true) {
    const int items = scanf("%lf", &amount);

    if (items > 0) {
      break;
    }

    printf("Please enter a number\n");
    char temp;
    while ((temp = fgetc(stdin)) != EOF) {
      if (temp == '\n') {
        break;
      }
    }
  }

  double balance = Account_GetBalance(account);
  balance -= amount;
  Account_SetBalance(account, balance);

  printf("%f EUR paid.\n", amount);
  printf("Balance: %f EUR.\n\n", Account_GetBalance(account));

  char customer_receipt[MAX_STRING_SIZE];
  sprintf(customer_receipt, "customer_receipt_%d.txt", Account_GetId(account));
  const char* bank_receipt = "customer_receipt.txt";

  FILE* customer_receipt_file = fopen(customer_receipt, "a");
  fprintf(customer_receipt_file, "%f EUR paid.\n", amount);
  fprintf(customer_receipt_file, "Balance: %f EUR.\n\n",
          Account_GetBalance(account));
  fclose(customer_receipt_file);

  FILE* bank_receipt_file = fopen(bank_receipt, "a");
  fprintf(bank_receipt_file, "Account %d:\n", Account_GetId(account));
  fprintf(bank_receipt_file, "%f EUR paid.\n", amount);
  fprintf(bank_receipt_file, "Balance: %f EUR.\n\n",
          Account_GetBalance(account));
  fclose(bank_receipt_file);
}
