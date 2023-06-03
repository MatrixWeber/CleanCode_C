#include "tools.h"
#include <stdbool.h>
#include <stdio.h>

static void ShowErrorCleanUp();

void ReadText(const char* message, char* buffer)
{
  printf("%s ", message);
  scanf("%s", buffer);
}

int ReadNumber(const char* message)
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
