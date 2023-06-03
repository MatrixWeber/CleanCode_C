#ifndef BANK_H
#define BANK_H

#include "account.h"

#define MAX_ACCOUNTS 10

typedef struct Bank_ {
  Account account_objects[MAX_ACCOUNTS];
  Account* accounts[MAX_ACCOUNTS];
} Bank;

void Bank_Init(Bank* self);
void Bank_CreateAccount(Bank* self);
void Bank_Deposit(Bank* self);
void Bank_Withdraw(Bank* self);
void Bank_ShowBalance(Bank* self);

#endif  // BANK_H
