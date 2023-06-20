#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "i_factoryable.h"

typedef struct {
  char last_operation;
  IFactoryable* factory;
  double (*calculate)(const char, const double, const double);
  char (*getLastOperation)();
} Calculator;

void Calculator_Init(Calculator*const self, IFactoryable*const factory);

#endif  // CALCULATOR_H
