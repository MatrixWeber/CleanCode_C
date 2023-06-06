#include "account.h"
#include "logger.h"

void Account_Init(Account *self) {
    self->balance = 0.0;
}

double Account_GetBalance(Account *self) { return self->balance; }

void Account_SetInterest(Account *self, InterestCalculator *const interest_calculator) {
    self->interest_calculator = interest_calculator;
}

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
    double interest_rate = 0;
    if (self->interest_calculator) {
        interest_rate = self->interest_calculator->calculate_interest(self->interest_calculator);
    }

    const double interest = self->balance * interest_rate;

    Log("\nCalculate interest, amount: ");
    LogDouble(interest);
    Log("\n");

    return interest;
}
