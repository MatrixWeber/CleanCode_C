#include "calculator.h"
#include "i_operationable.h"

void Calculator_Init(Calculator*const self, IFactoryable*const factory)
{
    self->last_operation = '+';
    self->factory = factory;
}

char Calculator_GetLastOperation(const Calculator *const self) {
    return self->last_operation;
}

double Calculator_Calculate(Calculator *const self, const char operation, const double left_operand, const double right_operand) {
    IOperationable* operationable = self->factory->create(operation);
    self->last_operation = operationable->lastOperation();
    return operationable->execute(left_operand, right_operand);
}
