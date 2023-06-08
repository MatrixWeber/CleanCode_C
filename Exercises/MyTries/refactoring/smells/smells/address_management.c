#include "address_management.h"
#include "address.h"

static void AddressManagement_SetNumberOfAddresses(AddressManagement *const self, const int number_of_addresses) {
    if (number_of_addresses > MAX_NUMBER_OF_ADDRESSES) {
        self->number_of_addresses = MAX_NUMBER_OF_ADDRESSES;
    } else {
        self->number_of_addresses = number_of_addresses;
    }
}

void AddressManagement_Init(AddressManagement *const self,
                            const int number_of_addresses) {
    AddressManagement_SetNumberOfAddresses(self, number_of_addresses);

    for (int i = 0; i < self->number_of_addresses; ++i) {
        Address_Init(&self->addresses[i]);
    }
}

void AddressManagement_ReadAllAddresses(AddressManagement *const self) {
    for (int i = 0; i < self->number_of_addresses; ++i) {
        Address_Read(&self->addresses[i]);
    }
}

void AddressManagement_PrintAllAddresses(AddressManagement *const self) {
    for (int i = 0; i < self->number_of_addresses; ++i) {
        Address_Show(&self->addresses[i]);
    }
}
