#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "bank.h"
#include "console.h"

int main() {
    Bank bank;
    Bank_Init(&bank);

    while (true) {
        Console_Write("Welcome to the Bank of the Universe\n");
        Console_Write("Please press a button\n");
        Console_Write("'c' - Create new account\n");
        Console_Write("'d' - Deposit\n");
        Console_Write("'w' - Withdraw\n");
        Console_Write("'s' - Show balance\n");
        Console_Write("'q' - Quit program\n");

        const char c = getchar();

        Console_Write("\n");

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

