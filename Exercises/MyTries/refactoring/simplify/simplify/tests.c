#include <math.h>
#include "tests.h"
#include "../../test_framework/test_functions.h"
#include "calculator.h"
#include "plus_operation.h"
#include "minus_operation.h"
#include "multiply_operation.h"
#include "divide_operation_proxy.h"

TEST(TestCalculatorAddition) {
    Calculator calc;
    Calculator_Init(&calc);
    PlusOperation operation;
    PlusOperation_Init(&operation);

    const double first_value = 2.1;
    const double second_value = 4.2;
    ASSERT(calc.calculate(&operation.operationable, first_value, second_value) ==
           first_value + second_value,
           "Addition failed");
}

TEST(TestCalculatorSubtraction) {
    Calculator calc;
    Calculator_Init(&calc);
    MinusOperation operation;
    MinusOperation_Init(&operation);
    const double first_value = 2.1;
    const double second_value = 4.2;
    ASSERT(calc.calculate(&operation.operationable, first_value, second_value) ==
           first_value - second_value,
           "Subtraction failed");
}

TEST(TestCalculatorMultiply) {
    Calculator calc;
    Calculator_Init(&calc);
    MultiplyOperation operation;
    MultiplyOperation_Init(&operation);
    const double first_value = 2.1;
    const double second_value = 4.2;
    ASSERT(calc.calculate(&operation.operationable, first_value, second_value) ==
           first_value * second_value,
           "Multiply failed");
}

TEST(TestCalculatorDivision) {
    Calculator calc;
    Calculator_Init(&calc);
    DivideOperationProxy operation;
    DivideOperationProxy_Init(&operation);
    const double first_value = 2.1;
    const double second_value = 4.2;
    ASSERT(calc.calculate(&operation.operationable, first_value, second_value) ==
           first_value / second_value,
           "Division failed");
}

TEST(TestCalculatorLastOperationValid) {
    const char operation = '/';
    Calculator calc;
    Calculator_Init(&calc);

    DivideOperationProxy divide_operation;
    DivideOperationProxy_Init(&divide_operation);
    const double first_value = 2.1;
    const double second_value = 4.2;
    calc.calculate(&divide_operation.operationable, first_value, second_value);

    ASSERT(calc.getLastOperation() == operation,
           "GetLastOperation failed");
}

TEST(TestCalculatorDivisionByZero) {
    Calculator calc;
    Calculator_Init(&calc);
    DivideOperationProxy divide_operation;
    DivideOperationProxy_Init(&divide_operation);
    const double first_value = 2.1;
    const double second_value = 0;

    ASSERT(calc.calculate(&divide_operation.operationable, first_value, second_value) ==
           0,
           "Division by zero failed");
}

TEST_SUITE(TestAddressManagement) {
    RUN_TEST(TestCalculatorAddition);
    RUN_TEST(TestCalculatorSubtraction);
    RUN_TEST(TestCalculatorMultiply);
    RUN_TEST(TestCalculatorDivision);
    RUN_TEST(TestCalculatorLastOperationValid);
    RUN_TEST(TestCalculatorDivisionByZero);
}

void RunTests() { RUN_TEST_SUITE(TestAddressManagement); }
