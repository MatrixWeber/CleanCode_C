#include "source/up_counter.h"

void UpCounter_Init(UpCounter *const self, const int lower_limit, const int upper_limit) {
    Counter_InitLimits(&self->base, lower_limit, upper_limit);
}

void UpCounter_Count(UpCounter *const self)
{
    Counter_Count(&self->base, 1);
}