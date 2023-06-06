#ifndef BANK_H
#define BANK_H

#include "account.h"

#define MAX_ACCOUNTS 20

typedef struct Bank_ {
  Account account_objects[MAX_ACCOUNTS];
  Account* accounts[MAX_ACCOUNTS];
} Bank;

void Bank_Init(Bank *self);
Account* Bank_CreateAccount(Bank* self);

void Bank_PayInterest(Bank* self);

#endif  // BANK_H
