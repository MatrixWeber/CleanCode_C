//
// Created by SW on 08.06.2023.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "console.h"

int ReadNumber(const char *const name) {
    int number = 0;
    while (true) {
        printf("Please enter the %s: ", name);
        const int items = scanf_s("%d", &number);

        if (items > 0) {
            break;
        }

        printf("Please enter a number\n");
        int temp;
        while ((temp = fgetc(stdin)) != EOF) {
            if (temp == '\n') {
                break;
            }
        }
    }
    return number;
}

void Print(const char *text) { printf("%s", text); }

const char *ReadString() {
    static char string[] = {'\0'};
    scanf("%s", string);
    return string;
}