#ifndef BANK_H
#define BANK_H

#include "account.h"

#define MAX_ACCOUNTS 10

typedef struct Bank_ {
  Account account_objects[MAX_ACCOUNTS];
  Account* accounts[MAX_ACCOUNTS];
} Bank;

void Bank_Init(Bank *const self);
void Bank_CreateAccount(Bank *const self);
void Bank_Deposit(Bank *const self);
void Bank_Withdraw(Bank *const self);

void Bank_ShowBalance(Bank *const self);

#endif  // BANK_H
