#include "source/up_counter.h"

void UpCounter_Init(UpCounter* self, int lower_limit, int upper_limit) {
  Counter_InitLimits(&self->base, lower_limit, upper_limit);
}

void UpCounter_Count(UpCounter* self) { Counter_Count(&self->base, 1); }
