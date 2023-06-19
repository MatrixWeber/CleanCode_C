#ifndef BANK_H
#define BANK_H

#include "account.h"

#define MAX_ACCOUNTS 10

typedef struct {
  Account account_objects[MAX_ACCOUNTS];
  Account* accounts[MAX_ACCOUNTS];
} Bank;

void Bank_Init(Bank *const self);
Account* Bank_CreateAccount(Bank *const self);

void Bank_PayInterest(Bank *const self);

#endif  // BANK_H
