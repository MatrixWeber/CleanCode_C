#ifndef COUNTER_H
#define COUNTER_H

typedef struct Counter_ {
  int value;
  int max_value;
} Counter;

void Counter_Init(Counter* self);
void Counter_InitValue(Counter* self, const int value);
void Counter_InitValueMax(Counter* self, const int value, const int max_value);

void Counter_SetValue(Counter* self, const int value);
int Counter_GetValue(Counter* self);
void Counter_Count(Counter* self, const int step);

#endif  // COUNTER_H
