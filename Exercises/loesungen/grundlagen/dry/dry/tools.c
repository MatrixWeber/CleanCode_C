#include "tools.h"
#include <stdbool.h>
#include <stdio.h>

void ShowErrorCleanUp()
{
  printf("Please enter a number\n");
  char temp;
  while ((temp = fgetc(stdin)) != EOF) {
    if (temp == '\n') {
      break;
    }
  }
}

int ReadInteger(const char* message)
{
  printf("%s: ", message);

  while (true) {
    int number;
    const int items = scanf("%d", &number);

    if (items > 0) {
      return number;
    }

    ShowErrorCleanUp();
  }
}

double ReadDouble(const char* message)
{
  printf("%s: ", message);

  while (true) {
    double number;
    const int items = scanf("%lf", &number);

    if (items > 0) {
      return number;
    }

    ShowErrorCleanUp();
  }
}
