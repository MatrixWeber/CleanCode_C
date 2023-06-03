// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_COUNTER_H_
#define SOURCE_COUNTER_H_

typedef struct _Counter {
  int value;
} Counter;

void Counter_Init(Counter* self);

void Counter_Count(Counter* self, int amount);
int Counter_GetValue(const Counter* self);
void Counter_Reset(Counter* self);

#endif  // SOURCE_COUNTER_H_
