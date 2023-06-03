#include "address_management.h"
#include <stdio.h>

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
    Address_Init(&self->addresses[i]);
  }
}

void AddressManagement_ReadAllAddresses(AddressManagement* self)
{
  for (int i = 0; i < self->number_of_addresses; ++i) {
    Address_Read(&self->addresses[i]);
    printf("\n");
  }
}

void AddressManagement_WriteAllAddresses(const AddressManagement* self)
{
  for (int i = 0; i < self->number_of_addresses; ++i) {
    Address_Show(&self->addresses[i]);
  }
}

int AddressManagement_GetNumberOfAddresses(const AddressManagement* self)
{
  return self->number_of_addresses;
}
