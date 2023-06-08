//
// Created by SW on 08.06.2023.
//

#include "multiply_operation.h"

static MultiplyOperation* this;

static void RegisterThis(MultiplyOperation*const self)
{
    this = self;
}

static char lastOperation()
{
    return '*';
}
static double execute(const double left_operand, const double right_operand)
{
    return left_operand * right_operand;
}

void MultiplyOperation_Init(MultiplyOperation*const self)
{
    self->RegisterThis = RegisterThis;
    self->RegisterThis(self);
    self->operationable.execute = execute;
    self->operationable.lastOperation = lastOperation;

}