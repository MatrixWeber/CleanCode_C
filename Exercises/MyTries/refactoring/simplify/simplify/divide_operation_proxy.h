//
// Created by SW on 08.06.2023.
//

#ifndef SIMPLIFY_DIVIDE_OPERATION_PROXY_H
#define SIMPLIFY_DIVIDE_OPERATION_PROXY_H

#include "i_operationable.h"
#include "divide_operation.h"

typedef struct
{
    DivideOperation divide_operation;
    IOperationable operationable;
} DivideOperationProxy;

void DivideOperationProxy_Init(DivideOperationProxy*const self);

#endif //SIMPLIFY_DIVIDE_OPERATION_PROXY_H
