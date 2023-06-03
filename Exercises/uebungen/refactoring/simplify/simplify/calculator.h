#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef struct Calculator_ {
  char last_operation;
} Calculator;

void Calculator_Init(Calculator* self);
double Calculator_Calculate(Calculator* self, const char operation,
                            const double left_operand,
                            const double right_operand);
char Calculator_GetLastOperation(const Calculator* self);

#endif  // CALCULATOR_H
