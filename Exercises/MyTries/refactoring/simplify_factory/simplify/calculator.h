#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "i_operationable.h"
#include "i_factoryable.h"

typedef struct Calculator Calculator;

struct Calculator{
  char last_operation;
  IFactoryable* factory;
  double (*Calculate)(const char, const double, const double);
  char (*GetLastOperation)();
};

void Calculator_Init(Calculator*const self, IFactoryable*const factory);

#endif  // CALCULATOR_H
