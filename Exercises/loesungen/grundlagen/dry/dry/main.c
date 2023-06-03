#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "bank.h"

int main()
{
  Bank bank;
  Bank_Init(&bank);

  while (true) {
    printf("Welcome to the Bank of the Universe\n");
    printf("Please press a button\n");
    printf("'c' - Create new account\n");
    printf("'d' - Deposit\n");
    printf("'w' - Withdraw\n");
    printf("'s' - Show balance\n");
    printf("'q' - Quit program\n");

    const char c = getchar();

    printf("\n");

    switch (tolower(c)) {
      case 'q':
        return 0;

      case 'c':
        Bank_CreateAccount(&bank);
        break;

      case 'd':
        Bank_Deposit(&bank);
        break;

      case 'w':
        Bank_Withdraw(&bank);
        break;

      case 's':
        Bank_ShowBalance(&bank);
        break;

      default:
        break;
    }

    char temp;
    while ((temp = fgetc(stdin)) != EOF) {
      if (temp == '\n') {
        break;
      }
    }
  }
}
