#include "calculator.h"
#include "i_operationable.h"

static Calculator* this;
static void RegisterThis(Calculator*const self)
{
    this = self;
}

static double Calculate(const char operation, const double left_operand, const double right_operand) {
    IOperationable* operationable = this->factory->create(operation);
    this->last_operation = operationable->lastOperation();
    return operationable->execute(left_operand, right_operand);
}

static char GetLastOperation() {
    return this->last_operation;
}

void Calculator_Init(Calculator*const self, IFactoryable*const factory)
{
    RegisterThis(self);
    self->last_operation = '+';
    self->factory = factory;
    self->Calculate = Calculate;
    self->GetLastOperation = GetLastOperation;
}
