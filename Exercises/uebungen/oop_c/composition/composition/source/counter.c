// Copyright 2018 MicroConsult GmbH
#include "source/counter.h"

void Counter_Init(Counter* self) { Counter_Reset(self); }

void Counter_Count(Counter* self, int amount) { self->value += amount; }

int Counter_GetValue(const Counter* self) { return self->value; }

void Counter_Reset(Counter* self) { self->value = 0; }
