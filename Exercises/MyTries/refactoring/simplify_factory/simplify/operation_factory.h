//
// Created by SW on 08.06.2023.
//

#ifndef SIMPLIFY_OPERATIONFACTORY_H
#define SIMPLIFY_OPERATIONFACTORY_H

#include "i_factoryable.h"

typedef struct OperationFactory OperationFactory;

struct OperationFactory{
    void (*RegisterThis)(OperationFactory*const);
    IFactoryable factoryable;
};

void OperationFactory_Init(OperationFactory*const self);

#endif //SIMPLIFY_OPERATIONFACTORY_H
