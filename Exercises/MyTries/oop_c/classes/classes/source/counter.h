// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_COUNTER_H_
#define SOURCE_COUNTER_H_

typedef struct _Counter {
    int value;
} Counter;

 void Counter_Init(Counter *const self);

 void Counter_Count(Counter *const self, const int amount);
 int Counter_GetValue(Counter *const self);
 void Counter_Reset(Counter *const self);

#endif  // SOURCE_COUNTER_H_
