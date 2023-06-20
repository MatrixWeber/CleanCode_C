//
// Created by SW on 08.06.2023.
//

#ifndef SIMPLIFY_MULTIPLY_OPERATION_H
#define SIMPLIFY_MULTIPLY_OPERATION_H

#include "i_operationable.h"

typedef struct
{
    IOperationable operationable;
} MultiplyOperation;

void MultiplyOperation_Init(MultiplyOperation*const self);

#endif //SIMPLIFY_MULTIPLY_OPERATION_H
