#ifndef ADDRESS_H
#define ADDRESS_H

#include "i_logable.h"

#define MAX_NAME_SIZE 256

typedef struct Address Address;

struct Address{
    char name[MAX_NAME_SIZE];
    char street[MAX_NAME_SIZE];
    char city[MAX_NAME_SIZE];
    int zip_code;
    ILogable* i_logable;
    void (*addressShow)();
    void (*addressRead)();
};

void Address_Init(Address *const self, ILogable *const i_logable);

#endif  // ADDRESS_H
