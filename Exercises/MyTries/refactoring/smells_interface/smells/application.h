//
// Created by SW on 08.06.2023.
//

#ifndef SMELLS_APPLICATION_H
#define SMELLS_APPLICATION_H

#include "address_management.h"
#include "i_logable.h"

typedef struct Application Application;

struct Application {
    void (*init_this)(Application *const);
    AddressManagement address_management;
    void (*run)();
    ILogable* i_logable;
};

void Application_Init(Application *const self, const int number_of_addresses, ILogable *const i_logable);

#endif //SMELLS_APPLICATION_H
