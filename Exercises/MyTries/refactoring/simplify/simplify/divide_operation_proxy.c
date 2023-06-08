//
// Created by SW on 08.06.2023.
//

#include "divide_operation_proxy.h"

static DivideOperationProxy* this;

static void RegisterThis(DivideOperationProxy*const self)
{
    this = self;
}

static char lastOperation()
{
    return this->divide_operation.operationable.lastOperation();
}

static double execute(const double left_operand, const double right_operand)
{
    if(right_operand)
    {
        return this->divide_operation.operationable.execute(left_operand, right_operand);
    }
    return 0;
}

void DivideOperationProxy_Init(DivideOperationProxy*const self)
{
    self->RegisterThis = RegisterThis;
    self->RegisterThis(self);
    self->operationable.execute = execute;
    self->operationable.lastOperation = lastOperation;
    DivideOperation_Init(&self->divide_operation);
}