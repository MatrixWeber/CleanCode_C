#include "tests.h"
#include "../../test_framework/test_functions.h"
#include "calculator.h"

TEST(TestCalculatorAddition)
{
  Calculator calc;
  Calculator_Init(&calc);

  const double first_value = 2.1;
  const double second_value = 4.2;
  ASSERT(Calculator_Calculate(&calc, '+', first_value, second_value) ==
             first_value + second_value,
         "Addition failed");
}

TEST(TestCalculatorSubtraction)
{
  Calculator calc;
  Calculator_Init(&calc);

  const double first_value = 2.1;
  const double second_value = 4.2;
  ASSERT(Calculator_Calculate(&calc, '-', first_value, second_value) ==
             first_value - second_value,
         "Subtraction failed");
}

TEST(TestCalculatorMultiply)
{
  Calculator calc;
  Calculator_Init(&calc);

  const double first_value = 2.1;
  const double second_value = 4.2;
  ASSERT(Calculator_Calculate(&calc, '*', first_value, second_value) ==
             first_value * second_value,
         "Multiply failed");
}

TEST(TestCalculatorDivision)
{
  Calculator calc;
  Calculator_Init(&calc);

  const double first_value = 2.1;
  const double second_value = 4.2;
  ASSERT(Calculator_Calculate(&calc, '/', first_value, second_value) ==
             first_value / second_value,
         "Division failed");
}

TEST(TestCalculatorLastOperationValid)
{
  const char operation = '/';
  Calculator calc;
  Calculator_Init(&calc);

  const double first_value = 2.1;
  const double second_value = 4.2;
  Calculator_Calculate(&calc, operation, first_value, second_value);

  ASSERT(Calculator_GetLastOperation(&calc) == operation,
         "GetLastOperation failed");
}

TEST(TestCalculatorLastOperationInvalid)
{
  const char invalid_operation = ';';
  Calculator calc;
  Calculator_Init(&calc);

  const double first_value = 2.1;
  const double second_value = 4.2;

  const char last_operation = Calculator_GetLastOperation(&calc);
  Calculator_Calculate(&calc, invalid_operation, first_value, second_value);

  ASSERT(Calculator_GetLastOperation(&calc) == last_operation,
         "GetLastOperation failed");
}

TEST_SUITE(TestAddressManagement)
{
  RUN_TEST(TestCalculatorAddition);
  RUN_TEST(TestCalculatorSubtraction);
  RUN_TEST(TestCalculatorMultiply);
  RUN_TEST(TestCalculatorDivision);
  RUN_TEST(TestCalculatorLastOperationValid);
  RUN_TEST(TestCalculatorLastOperationInvalid);
}

void RunTests() { RUN_TEST_SUITE(TestAddressManagement); }
