//
// Created by SW on 08.06.2023.
//

#include "operation_factory.h"
#include "null_operation.h"
#include "plus_operation.h"
#include "minus_operation.h"
#include "multiply_operation.h"
#include "divide_operation.h"

static OperationFactory *this;

static IOperationable *create(const char operation) {
    switch (operation) {
        case '+': {
            static PlusOperation plus_operation;
            PlusOperation_Init(&plus_operation);
            return &plus_operation.operationable;
        }

        case '-': {
            static MinusOperation minus_operation;
            MinusOperation_Init(&minus_operation);
            return &minus_operation.operationable;
        }

        case '*': {
            static MultiplyOperation multiply_operation;
            MultiplyOperation_Init(&multiply_operation);
            return &multiply_operation.operationable;
        }

        case '/': {
            static DivideOperation divide_operation;
            DivideOperation_Init(&divide_operation);
            return &divide_operation.operationable;
        }
        default:
            static NullOperation null_operation;
            NullOperation_Init(&null_operation);
            return &null_operation.operationable;
    }
}

void OperationFactory_Init(OperationFactory *const self) {
    this = self;
    self->factoryable.create = create;
}