//
// Created by SW on 08.06.2023.
//

#ifndef SIMPLIFY_DIVIDE_OPERATION_H
#define SIMPLIFY_DIVIDE_OPERATION_H

#include "i_operationable.h"

typedef struct
{
    IOperationable operationable;
} DivideOperation;

void DivideOperation_Init(DivideOperation*const self);

#endif //SIMPLIFY_DIVIDE_OPERATION_H
