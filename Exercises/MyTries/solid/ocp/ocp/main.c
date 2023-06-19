
#include "account.h"
#include "bank.h"
#include "logger.h"

int main()
{
    LogText("Banking program: Start\n");

  Bank bank;

  Bank_Init(&bank);
    {
        InterestCalculator interest_calculator;
        InterestCalculator_Init(&interest_calculator, 0.01);
        for (int i = 0; i < 8; i++) {
            Account *account = Bank_CreateAccount(&bank);
            Account_Deposit(account, 20.0);
            Account_SetInterest(account, &interest_calculator);
        }
    }
    {
        InterestCalculator interest_calculator;
        InterestCalculator_Init(&interest_calculator, 0.75);
        for (int i = 0; i < 8; i++) {
            Account *account = Bank_CreateAccount(&bank);
            Account_Deposit(account, 20.0);
            Account_SetInterest(account, &interest_calculator);
        }
    }

  Bank_PayInterest(&bank);

    LogText("\nBanking program: End\n");

  return 0;
}
