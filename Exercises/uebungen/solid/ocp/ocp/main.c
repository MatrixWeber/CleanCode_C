
#include "account.h"
#include "bank.h"
#include "logger.h"

int main()
{
  Log("Banking program: Start\n");

  Bank bank;
  Bank_Init(&bank);

  for (int i = 0; i < 8; i++) {
    Account* account = Bank_CreateAccount(&bank);
    Account_Deposit(account, 20.0);
    Account_SetType(account, kCheckingAccount);
  }

  for (int i = 0; i < 10; i++) {
    Account* account = Bank_CreateAccount(&bank);
    Account_Deposit(account, 20.0);
    Account_SetType(account, kSavingsAccount);
  }

  Bank_PayInterest(&bank);

  Log("\nBanking program: End\n");

  return 0;
}
