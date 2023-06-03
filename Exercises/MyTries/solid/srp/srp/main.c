#include "bank.h"

int main()
{
  Bank bank;
  Bank_Init(&bank);

  for (int i = 0; i < 8; i++) {
    Account* account = Bank_CreateAccount(&bank);
    Account_Deposit(account, i * 2.0);
  }

  Bank_PayInterest(&bank);

  return 0;
}
