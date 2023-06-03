#include "calculator.h"
#include <math.h>

void Calculator_Init(Calculator* self) { self->last_operation = '+'; }

char Calculator_GetLastOperation(const Calculator* self)
{
  return self->last_operation;
}

double Calculator_Calculate(Calculator* self, const char operation,
                            const double left_operand,
                            const double right_operand)
{
  double result = NAN;

  switch (operation) {
    case '+': {
      result = left_operand + right_operand;
      break;
    }

    case '-': {
      result = left_operand - right_operand;
      break;
    }

    case '*': {
      result = left_operand * right_operand;
      break;
    }

    case '/': {
      result = left_operand / right_operand;
      break;
    }

    default:
      return result;
  }

  self->last_operation = operation;
  return result;
}
