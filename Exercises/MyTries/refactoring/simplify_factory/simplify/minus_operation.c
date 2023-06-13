//
// Created by SW on 08.06.2023.
//

#include "minus_operation.h"

static MinusOperation* this;

static void RegisterThis(MinusOperation*const self)
{
    this = self;
}

static char lastOperation()
{
    return '-';
}
static double execute(const double left_operand, const double right_operand)
{
    return left_operand - right_operand;
}

void MinusOperation_Init(MinusOperation*const self)
{
    RegisterThis(self);
    self->operationable.execute = execute;
    self->operationable.lastOperation = lastOperation;

}