//
// Created by SW on 08.06.2023.
//

#ifndef SIMPLIFY_MINUS_OPERATION_H
#define SIMPLIFY_MINUS_OPERATION_H

#include "i_operationable.h"

typedef struct
{
    IOperationable operationable;
} MinusOperation;

void MinusOperation_Init(MinusOperation*const self);

#endif //SIMPLIFY_MINUS_OPERATION_H
