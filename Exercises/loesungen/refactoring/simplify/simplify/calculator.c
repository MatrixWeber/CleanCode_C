#include "calculator.h"
#include <math.h>

// private members ...
typedef struct {
  char operation_id;
  double (*operation_func)(const double, const double);
} OperationInfo;

static double Add(const double lhs, const double rhs) { return lhs + rhs; }
static double Sub(const double lhs, const double rhs) { return lhs - rhs; }
static double Mul(const double lhs, const double rhs) { return lhs * rhs; }
static double Div(const double lhs, const double rhs) { return lhs / rhs; }

OperationInfo operations[] = {
    {'+', Add},
    {'-', Sub},
    {'*', Mul},
    {'/', Div},
};

static const int number_of_operations =
    sizeof(operations) / sizeof(OperationInfo);

// public members ...
void Calculator_Init(Calculator* self) { self->last_operation = '+'; }

char Calculator_GetLastOperation(const Calculator* self)
{
  return self->last_operation;
}

double Calculator_Calculate(Calculator* self, const char operation,
                            const double left_operand,
                            const double right_operand)
{
  for (int i = 0; i < number_of_operations; ++i) {
    if (operations[i].operation_id == operation) {
      self->last_operation = operation;
      return operations[i].operation_func(left_operand, right_operand);
    }
  }

  return NAN;
}
