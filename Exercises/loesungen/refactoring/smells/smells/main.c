#include <stdbool.h>
#include <stdio.h>
#include "address_management.h"

// Zu lange Funktion
int main()
{
  int number_of_addresses;

  // Verdoppelung: Einlesen einer Zahl (gibt es schon in der Klasse Address)
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

  AddressManagement_WriteAllAddresses(&address_management);

  return 0;
}
