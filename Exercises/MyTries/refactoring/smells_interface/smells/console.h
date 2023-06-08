//
// Created by SW on 08.06.2023.
//

#ifndef SMELLS_CONSOLE_H
#define SMELLS_CONSOLE_H

#include "i_logable.h"

typedef struct
{
    ILogable i_Logable;
} Console;

void Console_Init(Console*const self);

#endif //SMELLS_CONSOLE_H
