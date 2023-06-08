//
// Created by SW on 08.06.2023.
//

#ifndef SIMPLIFY_I_OPERATIONABLE_H
#define SIMPLIFY_I_OPERATIONABLE_H

typedef struct
{
    char (*lastOperation)();
    double (*execute)(const double, const double);
} IOperationable;

#endif //SIMPLIFY_I_OPERATIONABLE_H
