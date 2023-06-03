#include "source/down_counter.h"

void DownCounter_Init(DownCounter* self, int lower_limit, int upper_limit) {
  Counter_InitLimits(&self->base, lower_limit, upper_limit);
  self->base.value = RangeChecker_GetUpperLimit(&self->base.checker);
}

void DownCounter_Count(DownCounter* self) { Counter_Count(&self->base, -1); }
