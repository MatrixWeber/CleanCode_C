
#include "account.h"
#include "bank.h"
#include "logger.h"

int main() {
    LogText("Banking program: Start\n");

    Bank bank;

    Bank_Init(&bank);
    {
        InterestCalculator interest_calculator;
        InterestCalculator_Init(&interest_calculator, 0.001);
        for (int i = 0; i < 8; i++) {
            Account *checking_account = Bank_CreateAccount(&bank);
            Account_Deposit(checking_account, 20.0 * i);
            Account_SetInterest(checking_account, &interest_calculator);
        }
    }
    {
        InterestCalculator interest_calculator;
        InterestCalculator_Init(&interest_calculator, 0.0075);
        for (int i = 0; i < 10; i++) {
            Account *saving_account = Bank_CreateAccount(&bank);
            Account_Deposit(saving_account, 10.0 * i);
            Account_SetInterest(saving_account, &interest_calculator);
        }
    }

    Bank_PayInterest(&bank);

    LogText("\nBanking program: End\n");

    return 0;
}
