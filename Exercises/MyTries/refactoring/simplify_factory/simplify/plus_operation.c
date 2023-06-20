//
// Created by SW on 08.06.2023.
//

#include "plus_operation.h"

static PlusOperation* this;

static char lastOperation()
{
    return '+';
}
static double execute(const double left_operand, const double right_operand)
{
    return left_operand + right_operand;
}

void PlusOperation_Init(PlusOperation*const self)
{
    this = self;
    self->operationable.execute = execute;
    self->operationable.lastOperation = lastOperation;

}