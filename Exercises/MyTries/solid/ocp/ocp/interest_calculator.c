//
// Created by SW on 05.06.2023.
//

#include "interest_calculator.h"

static double InterestCalculator_CalculateInterest(InterestCalculator *const self, double value)
{
    return self->interest_rate * value;
}

void InterestCalculator_Init(InterestCalculator*const self, const double interest_rate)
{
    self->interest_rate = interest_rate;
    self->calculate_interest = InterestCalculator_CalculateInterest;
}

