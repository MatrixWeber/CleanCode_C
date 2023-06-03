#include "counter.h"
#include <limits.h>
#include <stdbool.h>

void Counter_Init(Counter* self)
{
  self->value = 0;
  self->max_value = INT_MAX;
}

void Counter_InitValue(Counter* self, int value)
{
  self->value = value;
  self->max_value = INT_MAX;
}

void Counter_InitValueMax(Counter* self, int value, int max_value)
{
  self->value = value;
  self->max_value = max_value;
}

void Counter_SetValue(Counter* self, int value) { self->value = value; }

int Counter_GetValue(Counter* self) { return self->value; }

void Counter_Count(Counter* self, int step)
{
  self->value = self->value + step;

  if ((self->value >= self->max_value) == true) {
    self->value = 0;
  }
}
