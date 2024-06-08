//
// Created by SW on 08.06.2023.
//

#include "application.h"
#include "console.h"

static Application *this;

static void Application_Run() {
    Print("\n");
    AddressManagement_ReadAllAddresses(&this->address_management);
    Print("\n");

    AddressManagement_PrintAllAddresses(&this->address_management);
}

void Application_Init(Application *const self, const int number_of_addresses) {
    this = self;
    self->run = Application_Run;
    AddressManagement_Init(&self->address_management, number_of_addresses);
}