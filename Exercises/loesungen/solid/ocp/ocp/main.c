#include "account.h"
#include "bank.h"
#include "logger.h"

double CheckingAccountInterestCalculator(const double balance)
{
  return balance * 0.001;
}

double SavingsAccountInterestCalculator(const double balance)
{
  return balance * 0.0075;
}

void CreateAccounts(Bank* bank, const int number_of_accounts,
                    const double initial_balance,
                    InterestCalculatorFunction interest_calculator)
{
  for (int i = 0; i < number_of_accounts; i++) {
    Account* account = Bank_CreateAccount(bank);
    Account_Deposit(account, i * initial_balance);
    Account_SetInterestCalculator(account, interest_calculator);
  }
}

int main()
{
  Log("Banking program: Start\n");

  Bank bank;
  Bank_Init(&bank);

  CreateAccounts(&bank, 8, 20.0, CheckingAccountInterestCalculator);
  CreateAccounts(&bank, 8, 10.0, SavingsAccountInterestCalculator);

  Bank_PayInterest(&bank);

  Log("\nBanking program: End\n");

  return 0;
}
