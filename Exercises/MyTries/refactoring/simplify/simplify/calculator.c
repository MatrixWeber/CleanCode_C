#include "calculator.h"
#include "i_operationable.h"

static Calculator* this;

static char getLastOperation() {
    return this->last_operation;
}

static double calculate(const IOperationable *const operation, const double left_operand, const double right_operand) {
    this->last_operation = operation->lastOperation();
    return operation->execute(left_operand, right_operand);
}

void Calculator_Init(Calculator *self) {
    this = self;
    self->last_operation = '+';
    self->calculate = calculate;
    self->getLastOperation = getLastOperation;
}