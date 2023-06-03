#include "counter.h"
#include <limits.h>
#include <stdbool.h>

void Counter_Init(Counter* self) { Counter_InitValue(self, 0); }

void Counter_InitValue(Counter* self, const int value)
{
  Counter_InitValueMax(self, value, INT_MAX);
}

void Counter_InitValueMax(Counter* self, const int value, const int max_value)
{
  self->value = value;
  self->max_value = max_value;
}

void Counter_SetValue(Counter* self, const int value) { self->value = value; }

int Counter_GetValue(Counter* self) { return self->value; }

void Counter_Count(Counter* self, const int step)
{
  self->value = self->value + step;

  const bool is_overflow = self->value >= self->max_value;
  if (is_overflow) {
    self->value = 0;
  }
}
