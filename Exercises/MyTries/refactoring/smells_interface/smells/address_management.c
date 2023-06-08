#include <vcruntime.h>
#include "address_management.h"
#include "address.h"
static AddressManagement *this;

static void RegisterThis(AddressManagement *const self) {
    this = self;
};

static void AddressManagement_SetNumberOfAddresses(const int number_of_addresses) {
    if (number_of_addresses > MAX_NUMBER_OF_ADDRESSES) {
        this->number_of_addresses = MAX_NUMBER_OF_ADDRESSES;
    } else {
        this->number_of_addresses = number_of_addresses;
    }
}

static void AddressManagement_RegisterThis(AddressManagement *const self) {
    self->RegisterThis = RegisterThis;
    self->RegisterThis(self);
}

static void AddressManagement_ReadAllAddresses() {
    for (int i = 0; i < this->number_of_addresses; ++i) {
        this->addresses[i].addressRead();
    }
}

static void AddressManagement_PrintAllAddresses() {
    for (int i = 0; i < this->number_of_addresses; ++i) {
        this->addresses[i].addressShow();
    }
}

static void AddressManagement_RegisterPublicFunctions() {
    this->printAllAddresses = AddressManagement_PrintAllAddresses;
    this->readAllAddresses = AddressManagement_ReadAllAddresses;
}

void AddressManagement_Init(AddressManagement *const self, const int number_of_addresses, ILogable *const i_logable) {
    AddressManagement_RegisterThis(self);
    AddressManagement_SetNumberOfAddresses(number_of_addresses);
    AddressManagement_RegisterPublicFunctions();
    for (int i = 0; i < this->number_of_addresses; ++i) {
        Address_Init(&this->addresses[i], i_logable);
    }

}
