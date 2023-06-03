#ifndef ADDRESS_MANAGEMENT_H
#define ADDRESS_MANAGEMENT_H

#include "address.h"

#define MAX_NUMBER_OF_ADDRESSES 20

typedef struct AddressManagement_ {
  Address addresses[MAX_NUMBER_OF_ADDRESSES];
  int number_of_addresses;
} AddressManagement;

void AddressManagement_Init(AddressManagement* self,
                            const int number_of_addresses);

void AddressManagement_ReadAllAddresses(AddressManagement* self);
void AddressManagement_WriteAllAddresses(const AddressManagement* self);

int AddressManagement_GetNumberOfAddresses(const AddressManagement* self);

#endif  // ADDRESS_MANAGEMENT_H
