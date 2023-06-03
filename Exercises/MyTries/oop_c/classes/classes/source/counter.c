// Copyright 2018 MicroConsult GmbH
#include "source/counter.h"

void Counter_Init(Counter *const self) { Counter_Reset(self); }

void Counter_Count(Counter *const self, const int amount) { self->value += amount; }

int Counter_GetValue(Counter *const self) { return self->value; }

void Counter_Reset(Counter *const self) { self->value = 0; }