#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "i_operationable.h"
#include "i_factoryable.h"

typedef struct Calculator_ {
  char last_operation;
  IFactoryable* factory;
} Calculator;

void Calculator_Init(Calculator*const self, IFactoryable*const factory);
double Calculator_Calculate(Calculator*const self, const char operation, const double left_operand, const double right_operand);
char Calculator_GetLastOperation(const Calculator*const self);

#endif  // CALCULATOR_H
