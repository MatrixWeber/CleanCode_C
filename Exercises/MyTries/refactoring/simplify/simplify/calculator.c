#include "calculator.h"
#include "i_operationable.h"

void Calculator_Init(Calculator *self) { self->last_operation = '+'; }

char Calculator_GetLastOperation(const Calculator *self) {
    return self->last_operation;
}

double Calculator_Calculate(Calculator *self, const IOperationable *const operation, const double left_operand, const double right_operand) {
    self->last_operation = operation->lastOperation();
    return operation->execute(left_operand, right_operand);
}
