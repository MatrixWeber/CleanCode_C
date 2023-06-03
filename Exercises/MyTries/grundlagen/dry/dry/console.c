//
// Created by SW on 03.06.2023.
//

#include <stdio.h>
#include <stdbool.h>

void Console_Write(const char* text) { printf("%s", text); }

static bool isInputValid(const int items) {
    if (items > 0) {
        return true;
    }

    Console_Write("Please enter a number\n");
    char temp;
    while ((temp = fgetc(stdin)) != EOF) {
        if (temp == '\n') {
            return true;
        }
    };
    return false;
}

int Console_ReadNumber() {
    int number = 0;
    while (true) {
        const int items = scanf_s("%d", &number);
        if(isInputValid(items))
        {
            break;
        }
    }
    return number;
}

double Console_ReadDouble() {
    double number;
    while (true) {
        const int items = scanf_s("%lf", &number);
        if(isInputValid(items))
        {
            break;
        }
    }
    return number;
}