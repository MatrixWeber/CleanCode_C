#ifndef ADDRESS_MANAGEMENT_H
#define ADDRESS_MANAGEMENT_H

#include "address.h"

#define MAX_NUMBER_OF_ADDRESSES 20

typedef struct AddressManagement_ {
    Address addresses[MAX_NUMBER_OF_ADDRESSES];
    int number_of_addresses;
} AddressManagement;

void AddressManagement_Init(AddressManagement *const self, const int number_of_addresses);
void AddressManagement_ReadAllAddresses(AddressManagement *const self);
void AddressManagement_PrintAllAddresses(AddressManagement *const self);

#endif  // ADDRESS_MANAGEMENT_H
