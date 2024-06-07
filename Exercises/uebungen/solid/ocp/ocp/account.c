#include "account.h"
#include "logger.h"

void Account_Init(Account *self) {
    self->balance = 0.0;
    self->type = kInvalid;
}

double Account_GetBalance(Account *self) { return self->balance; }

AccountType Account_GetType(Account *self) { return self->type; }

void Account_SetType(Account *self, AccountType type) { self->type = type; }

void Account_Deposit(Account *self, double amount) {
    self->balance += amount;

    Log("\nDeposit, balance: ");
    LogDouble(self->balance);
    Log("\n");
}

double Account_Withdraw(Account *self, double amount) {
    self->balance -= amount;

    Log("\nWithdraw, balance: ");
    LogDouble(self->balance);
    Log("\n");

    return amount;
}

double Account_CalculateInterest(Account *self) {
    double interest_rate = 0.0;

    switch (self->type) {
        case kCheckingAccount: {
            interest_rate = 0.001;
            break;
        }

        // add case saving account

        case kInvalid:
            break;
    }

    const double interest = self->balance * interest_rate;

    Log("\nCalculate interest, amount: ");
    LogDouble(interest);
    Log("\n");

    return interest;
}
