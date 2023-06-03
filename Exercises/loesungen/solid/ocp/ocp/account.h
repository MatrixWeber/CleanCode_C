#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef double (*InterestCalculatorFunction)(double);

typedef struct Account_ {
  double balance;
  InterestCalculatorFunction interest_calculator;
} Account;

void Account_Init(Account* self);
double Account_GetBalance(Account* self);
void Account_SetInterestCalculator(
    Account* self, InterestCalculatorFunction interest_calculator);
void Account_Deposit(Account* self, double amount);
double Account_Withdraw(Account* self, double amount);
double Account_CalculateInterest(Account* self);

#endif  // ACCOUNT_H
