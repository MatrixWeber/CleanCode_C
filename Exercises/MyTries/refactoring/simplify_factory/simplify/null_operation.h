//
// Created by SW on 08.06.2023.
//

#ifndef SIMPLIFY_NULL_OPERATION_H
#define SIMPLIFY_NULL_OPERATION_H

#include "i_operationable.h"

typedef struct
{
    IOperationable operationable;
} NullOperation;

void NullOperation_Init(NullOperation*const self);

#endif //SIMPLIFY_NULL_OPERATION_H
