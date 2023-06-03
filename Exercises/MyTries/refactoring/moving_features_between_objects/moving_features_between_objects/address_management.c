#include "address_management.h"
#include <stdbool.h>
#include <stdio.h>

static void ReadAddress(Address* address);
static void ReadText(const char* message, char buffer[]);
static int ReadNumber(const char* message);

void AddressManagement_Init(AddressManagement* self,
                            const int number_of_addresses)
{
  if (number_of_addresses > MAX_NUMBER_OF_ADDRESSES) {
    self->number_of_addresses = MAX_NUMBER_OF_ADDRESSES;
  }
  else {
    self->number_of_addresses = number_of_addresses;
  }

  for (int i = 0; i < self->number_of_addresses; ++i) {
    self->addresses[i].city[0] = '\0';
    self->addresses[i].name[0] = '\0';
    self->addresses[i].street[0] = '\0';
    self->addresses[i].zip_code = 0;
  }
}

void AddressManagement_ReadAllAddresses(AddressManagement* self)
{
  for (int i = 0; i < self->number_of_addresses; ++i) {
    ReadAddress(&self->addresses[i]);
    printf("\n");
  }
}

void AddressManagement_WriteAllAddresses(const AddressManagement* self)
{
  for (int i = 0; i < self->number_of_addresses; ++i) {
    Address_Write(&self->addresses[i]);
  }
}

int AddressManagement_GetNumberOfAddresses(const AddressManagement* self)
{
  return self->number_of_addresses;
}

void ReadAddress(Address* address)
{
  ReadText("Please enter the name:", address->name);
  ReadText("Please enter the street:", address->street);
  address->zip_code = ReadNumber("Please enter the zip code:");
  ReadText("Please enter the city:", address->city);
}

void ReadText(const char* message, char buffer[])
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

    printf("Please enter a number\n");
    char temp;
    while ((temp = fgetc(stdin)) != EOF) {
      if (temp == '\n') {
        break;
      }
    }
  }
}
