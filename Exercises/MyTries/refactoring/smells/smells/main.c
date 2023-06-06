#include <stdbool.h>
#include <stdio.h>
#include "address_management.h"

int main()
{
  int number_of_addresses;

  while (true) {
    printf("Please enter the number of addresses: ");

    const int items = scanf("%d", &number_of_addresses);

    if (items > 0) {
      break;
    }

    printf("Please enter a number\n");
    char temp;
    while ((temp = fgetc(stdin)) != EOF) {
      if (temp == '\n') {
        break;
      }
    }
  }

  AddressManagement address_management;
  AddressManagement_Init(&address_management, number_of_addresses);
  printf("\n");

  AddressManagement_ReadAllAddresses(&address_management);
  printf("\n");

    AddressManagement_PrintAllAddresses(&address_management);

  return 0;
}
