// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_COUNTER_H_
#define SOURCE_COUNTER_H_

typedef struct {
    int value;
    void (*count)(const int);
    int (*getValue)();
    void (*reset)();
} Counter;

 void Counter_Init(Counter *const self);

#endif  // SOURCE_COUNTER_H_
