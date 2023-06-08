//
// Created by SW on 08.06.2023.
//

#ifndef SIMPLIFY_I_FACTORYABLE_H
#define SIMPLIFY_I_FACTORYABLE_H

#include "i_operationable.h"

typedef struct
{
    IOperationable* (*create)(const char);
} IFactoryable;

#endif //SIMPLIFY_I_FACTORYABLE_H
