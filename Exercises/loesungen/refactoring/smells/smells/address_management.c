#include "address_management.h"
#include <stdio.h>
#include "address.h"

static void ShowAddress(const char* name, const char* street, const char* city,
                        const int zip_code);

void AddressManagement_Init(AddressManagement* self,
                            const int number_of_addresses)
{
  if (number_of_addresses > MAX_NUMBER_OF_ADDRESSES) {
    self->number_of_addresses = MAX_NUMBER_OF_ADDRESSES;
  }
  else {
    self->number_of_addresses = number_of_addresses;
  }

  // es sollte Address_Init() verwendet werden
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
    Address_Read(&self->addresses[i]);
    printf("\n");
  }
}

void AddressManagement_WriteAllAddresses(AddressManagement* self)
{
  for (int i = 0; i < self->number_of_addresses; ++i) {
    // es sollte Address_Write verwendet werden
    ShowAddress(self->addresses[i].name, self->addresses[i].street,
                self->addresses[i].city, self->addresses[i].zip_code);
  }
}

// es sollte das vohandene Objekt Adress übergeben werden
// die Funktion ist überflüssig, sie ist schon in der Klasse Address enthalten
void ShowAddress(const char* name, const char* street, const char* city,
                 const int zip_code)
{
  printf("Name: %s\n", name);
  printf("Street: %s\n", street);
  printf("City: %d %s\n\n", zip_code, city);
}
