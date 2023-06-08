//
// Created by SW on 08.06.2023.
//

#include "application.h"
#include "console.h"

static Application *this;

static void Address_RegisterThis(Application *const self) {
    this = self;
};

static void Application_Run() {
    Print("\n");
    AddressManagement *const address_management = &this->address_management;
    AddressManagement_ReadAllAddresses(address_management);
    Print("\n");

    AddressManagement_PrintAllAddresses(address_management);
}

void Application_Init(Application *const self, const int number_of_addresses) {
    self->init_this = Address_RegisterThis;
    self->init_this(self);
    AddressManagement_Init(&self->address_management, number_of_addresses);
    self->run = Application_Run;
}