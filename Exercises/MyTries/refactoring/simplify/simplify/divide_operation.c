//
// Created by SW on 08.06.2023.
//

#include "divide_operation.h"

static DivideOperation* this;

static char lastOperation()
{
    return '/';
}
static double execute(const double left_operand, const double right_operand)
{
    return left_operand / right_operand;
}

void DivideOperation_Init(DivideOperation*const self)
{
    this = self;
    self->operationable.execute = execute;
    self->operationable.lastOperation = lastOperation;

}