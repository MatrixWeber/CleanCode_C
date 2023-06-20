#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "i_operationable.h"

typedef struct {
    char last_operation;
    double (*calculate)(const IOperationable *const, const double, const double);
    char (*getLastOperation)();
} Calculator;

void Calculator_Init(Calculator *self);

#endif  // CALCULATOR_H
