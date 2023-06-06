//
// Created by SW on 05.06.2023.
//

#ifndef OCP_INTEREST_CALCULATOR_H
#define OCP_INTEREST_CALCULATOR_H

typedef struct InterestCalculator InterestCalculator;

struct InterestCalculator{
    double interest_rate;
    double (*calculate_interest)(InterestCalculator *const);
};

void InterestCalculator_Init(InterestCalculator*const self, const double interest_rate);

#endif //OCP_INTEREST_CALCULATOR_H
