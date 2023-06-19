#include "account.h"
#include "logger.h"
#include <stdio.h>

void Account_Init(Account *const self) { self->balance = 0.0; }

double Account_GetBalance(const Account *const self) { return self->balance; }

void Account_Deposit(Account *const self, const double amount) {
    self->balance += amount;
    Log_Double("\nDeposit, amount: ", amount);
}

double Account_Withdraw(Account *const self, const double amount) {
    self->balance -= amount;

    Log_Double("\nWithdraw, amount: ", amount);
    return amount;
}

double Account_CalculateInterest(const Account *const self) {
    return self->balance * 0.001;
}

