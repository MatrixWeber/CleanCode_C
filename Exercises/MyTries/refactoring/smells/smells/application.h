//
// Created by SW on 08.06.2023.
//

#ifndef SMELLS_APPLICATION_H
#define SMELLS_APPLICATION_H

#include "address_management.h"

typedef struct Application Application;

struct Application {
    AddressManagement address_management;
    void (*run)();
};

void Application_Init(Application *const self, const int number_of_addresses);

#endif //SMELLS_APPLICATION_H
