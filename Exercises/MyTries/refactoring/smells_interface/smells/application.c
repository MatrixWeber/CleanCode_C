//
// Created by SW on 08.06.2023.
//

#include <vcruntime.h>
#include "application.h"
#include "console.h"

static Application *this;

static void Address_RegisterThis(Application *const self) {
    this = self;
};

static void Application_Run() {
    AddressManagement *const address_management = &this->address_management;
    ILogable *const log = this->i_logable;
    log->print("\n");
    address_management->readAllAddresses();
    log->print("\n");

    address_management->printAllAddresses();
}

void Application_Init(Application *const self, const int number_of_addresses, ILogable *const i_logable) {
    self->init_this = Address_RegisterThis;
    self->init_this(self);
    AddressManagement_Init(&self->address_management, number_of_addresses, i_logable);
    self->run = Application_Run;
    self->i_logable = i_logable;
}