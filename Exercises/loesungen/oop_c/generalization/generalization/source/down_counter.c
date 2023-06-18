#include "source/down_counter.h"

void DownCounter_Init(DownCounter *const self, const int lower_limit, const int upper_limit) {
    Counter_InitLimits(&self->base, lower_limit, upper_limit);
    self->base.value = RangeChecker_GetUpperLimit(&self->base.checker);
}

void DownCounter_Count(DownCounter *const self)
{
    Counter_Count(&self->base, -1);
}