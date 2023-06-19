#ifndef ADDRESS_MANAGEMENT_H
#define ADDRESS_MANAGEMENT_H

#include "address.h"
#include "i_logable.h"

#define MAX_NUMBER_OF_ADDRESSES 20


typedef struct  {
    Address addresses[MAX_NUMBER_OF_ADDRESSES];
    int number_of_addresses;
    void (*readAllAddresses)();
    void (*printAllAddresses)();
} AddressManagement;

void AddressManagement_Init(AddressManagement *const self, const int number_of_addresses, ILogable *const i_logable);

#endif  // ADDRESS_MANAGEMENT_H
