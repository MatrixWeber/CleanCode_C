//
// Created by SW on 08.06.2023.
//

#ifndef SMELLS_I_LOGABLE_H
#define SMELLS_I_LOGABLE_H

typedef struct
{
    int (*readNumber)(const char *const);
    void (*print)(const char *);
    const char *(*readString)();
} ILogable;

#endif //SMELLS_I_LOGABLE_H
