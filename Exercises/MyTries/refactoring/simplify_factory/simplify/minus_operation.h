//
// Created by SW on 08.06.2023.
//

#ifndef SIMPLIFY_MINUS_OPERATION_H
#define SIMPLIFY_MINUS_OPERATION_H

#include "i_operationable.h"

typedef struct MinusOperation MinusOperation;

struct MinusOperation
{
    void (*RegisterThis)(MinusOperation*const);
    IOperationable operationable;
};

void MinusOperation_Init(MinusOperation*const self);

#endif //SIMPLIFY_MINUS_OPERATION_H
