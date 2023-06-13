//
// Created by SW on 08.06.2023.
//

#include "divide_operation.h"

static DivideOperation* this;

static void RegisterThis(DivideOperation*const self)
{
    this = self;
}

static char lastOperation()
{
    return '/';
}
static double execute(const double left_operand, const double right_operand)
{
    if(right_operand)
    {
        return left_operand / right_operand;
    }
    return 0;
}

void DivideOperation_Init(DivideOperation*const self)
{
    RegisterThis(self);
    self->operationable.execute = execute;
    self->operationable.lastOperation = lastOperation;

}