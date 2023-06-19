//
// Created by SW on 08.06.2023.
//

#include "application.h"

static Application *this;

static void Application_Run() {
    AddressManagement *const address_management = &this->address_management;
    ILogable *const log = this->i_logable;
    log->print("\n");
    address_management->readAllAddresses();
    log->print("\n");

    address_management->printAllAddresses();
}

void Application_Init(Application *const self, const int number_of_addresses, ILogable *const i_logable) {
    this = self;
    AddressManagement_Init(&self->address_management, number_of_addresses, i_logable);
    self->run = Application_Run;
    self->i_logable = i_logable;
}