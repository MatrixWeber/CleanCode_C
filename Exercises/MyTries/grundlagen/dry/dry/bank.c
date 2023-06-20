#include "bank.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "account.h"
#include "console.h"
#include "disk.h"

static Account *CreateAccount(Bank *const self) {
    int account_index = -1;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (self->accounts[i] == NULL) {
            self->accounts[i] = &self->account_objects[i];
            account_index = i;
            break;
        }
    }

    if (account_index < 0) {
        Console_Write("Account cannot be created.\n");
    }

    Account *account = &self->account_objects[account_index];
    char text[50];
    sprintf_s(text, sizeof(text), "Account %d created.\n", Account_GetId(account));
    Console_Write(text);
    return account;
}

static void ShowBalance(Account *const account) {
    char text[50];
    sprintf_s(text, sizeof(text), "Balance: %.02f EUR.\n\n", Account_GetBalance(account));
    Console_Write(text);
};

static void ShowAccountNumNotExists(const int account_id) {
    char text[50];
    sprintf_s(text, sizeof(text), "Account number %d does not exist!\n\n", account_id);
    Console_Write(text);
};

static void ShowTransaction(const char* transaction, const double amount) {
    char text[100];
    sprintf_s(text, sizeof(text), "%.02f EUR %s.\n", amount, transaction);
    Console_Write(text);
};

void Bank_Init(Bank *const self) {
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        Account_Init(&self->account_objects[i], i + 1);
    }

    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        self->accounts[i] = NULL;
    }
}

static void WriteToFile(const char *file_name, const char *text) {
    Disk disk;
    Disk_Init(&disk, file_name);
    Disk_Write(&disk, text);
}

static Account *GetAccount(const Bank *const self, const int account_id) {
    Account *account = NULL;
    const int account_index = account_id - 1;
    if (account_index < 0 || account_index >= MAX_ACCOUNTS) {
        ShowAccountNumNotExists(account_id);
        return account;
    }

    return self->accounts[account_index];
}

static void WriteTransactionToFiles(Account *const account, const char transaction_text[100]) {
    char customer_receipt[MAX_STRING_SIZE];
    sprintf_s(customer_receipt, sizeof(customer_receipt), "customer_receipt_%d.txt", Account_GetId(account));
    char text[100];
    sprintf_s(text, sizeof(text), "Balance: %.02f EUR.\n\n", Account_GetBalance(account));
    WriteToFile(customer_receipt, text);

    const char *bank_receipt = "customer_receipt.txt";
    char text1[150];
    sprintf_s(text1, sizeof(text1), "Account %d:\n", Account_GetId(account));
    strcat_s(text1, 100, transaction_text);
    sprintf_s(text1, sizeof(text1), "Balance: %.02f EUR.\n\n", Account_GetBalance(account));
    WriteToFile(bank_receipt, text1);
}

static Account *Bank_ReadAccount(const Bank *const self) {
    Console_Write("Please enter your Account number: ");
    int account_id = Console_ReadNumber();
    Account *account = GetAccount(self, account_id);
    if (account == NULL) {
        ShowAccountNumNotExists(account_id);
    }
    return account;
}

static void ReportProcess(Account *const account, const double amount, const char *const process) {
    ShowTransaction("deposited", amount);
    ShowBalance(account);

    char text[100];
    sprintf_s(text, sizeof(text), "%.02f EUR paid.\n", amount);
    WriteTransactionToFiles(account, text);
}

static void ReportAccountId(const char *const file_name, const int account_id) {
    char text[100];
    sprintf_s(text, sizeof(text), "Account %d created.\n\n", account_id);
    WriteToFile(file_name, text);
}

void Bank_CreateAccount(Bank *const self) {
    Account *account = CreateAccount(self);
    if(account)
    {
        char customer_receipt[MAX_STRING_SIZE];
        sprintf_s(customer_receipt, sizeof(customer_receipt), "customer_receipt_%d.txt", Account_GetId(account));
        int account_id = Account_GetId(account);
        ReportAccountId(customer_receipt, account_id);
        ReportAccountId("customer_receipt.txt", account_id);
    }
}

void Bank_Deposit(Bank *const self) {
    Account *account = Bank_ReadAccount(self);
    if (account == NULL) {
        return;
    }

    Console_Write("Enter the amount: ");
    double amount = Console_ReadDouble();

    Account_ChangeBalance(account, amount);
    ReportProcess(account, amount, "deposited");

}

void Bank_Withdraw(Bank *const self) {
    Account *account = Bank_ReadAccount(self);
    if (account == NULL) {
        return;
    }
    Console_Write("Enter the amount: ");
    double amount = Console_ReadDouble();

    Account_ChangeBalance(account, -amount);
    ReportProcess(account, amount, "paid");
}

void Bank_ShowBalance(Bank *const self) {

    Account *account = Bank_ReadAccount(self);
    if (account == NULL) {
        return;
    }
    ShowBalance(account);
}

