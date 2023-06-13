#include "tests.h"
#include "../../test_framework/test_functions.h"
#include "calculator.h"
#include "operation_factory.h"

TEST(TestCalculatorAddition) {
    OperationFactory factory;
    OperationFactory_Init(&factory);
    Calculator calc;
    Calculator_Init(&calc, &factory.factoryable);

    const double first_value = 2.1;
    const double second_value = 4.2;
    ASSERT(calc.Calculate('+', first_value, second_value) == first_value + second_value, "Addition failed");
}

TEST(TestCalculatorSubtraction) {
    OperationFactory factory;
    OperationFactory_Init(&factory);
    Calculator calc;
    Calculator_Init(&calc, &factory.factoryable);
    const double first_value = 2.1;
    const double second_value = 4.2;
    ASSERT(calc.Calculate('-', first_value, second_value) == first_value - second_value, "Subtraction failed");
}

TEST(TestCalculatorMultiply) {
    OperationFactory factory;
    OperationFactory_Init(&factory);
    Calculator calc;
    Calculator_Init(&calc, &factory.factoryable);
    const double first_value = 2.1;
    const double second_value = 4.2;
    ASSERT(calc.Calculate('*', first_value, second_value) == first_value * second_value, "Multiply failed");
}

TEST(TestCalculatorDivision) {
    OperationFactory factory;
    OperationFactory_Init(&factory);
    Calculator calc;
    Calculator_Init(&calc, &factory.factoryable);
    const double first_value = 2.1;
    const double second_value = 4.2;
    ASSERT(calc.Calculate('/', first_value, second_value) == first_value / second_value, "Division failed");
}

TEST(TestCalculatorLastOperationValid) {
    const char operation = '/';
    OperationFactory factory;
    OperationFactory_Init(&factory);
    Calculator calc;
    Calculator_Init(&calc, &factory.factoryable);
    const double first_value = 2.1;
    const double second_value = 4.2;
    calc.Calculate('/', first_value, second_value);

    ASSERT(calc.GetLastOperation() == operation, "GetLastOperation failed");
}

TEST(TestCalculatorDivisionByZero) {
    OperationFactory factory;
    OperationFactory_Init(&factory);
    Calculator calc;
    Calculator_Init(&calc, &factory.factoryable);
    const double first_value = 2.1;
    const double second_value = 0;

    ASSERT(calc.Calculate('/', first_value, second_value) == 0, "Division by zero failed");
}

TEST(TestCalculatorInvalidOperation) {
    OperationFactory factory;
    OperationFactory_Init(&factory);
    Calculator calc;
    Calculator_Init(&calc, &factory.factoryable);
    const double first_value = 2.1;
    const double second_value = 0;

    ASSERT(calc.Calculate(';', first_value, second_value) == 0, "Invalid Operation failed");
}

TEST_SUITE(TestAddressManagement) {
    RUN_TEST(TestCalculatorAddition);
    RUN_TEST(TestCalculatorSubtraction);
    RUN_TEST(TestCalculatorMultiply);
    RUN_TEST(TestCalculatorDivision);
    RUN_TEST(TestCalculatorLastOperationValid);
    RUN_TEST(TestCalculatorDivisionByZero);
    RUN_TEST(TestCalculatorInvalidOperation);
}

void RunTests() { RUN_TEST_SUITE(TestAddressManagement); }
