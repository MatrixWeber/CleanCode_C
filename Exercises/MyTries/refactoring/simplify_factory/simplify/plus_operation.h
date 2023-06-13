//
// Created by SW on 08.06.2023.
//

#ifndef SIMPLIFY_PLUS_OPERATION_H
#define SIMPLIFY_PLUS_OPERATION_H

#include "i_operationable.h"

typedef struct PlusOperation PlusOperation;

struct PlusOperation
{
    IOperationable operationable;
};

void PlusOperation_Init(PlusOperation*const self);

#endif //SIMPLIFY_PLUS_OPERATION_H
