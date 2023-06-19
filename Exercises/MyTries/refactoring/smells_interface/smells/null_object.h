//
// Created by SW on 08.06.2023.
//

#ifndef SMELLS_NULLOBJECT_H
#define SMELLS_NULLOBJECT_H

#include "i_logable.h"

typedef struct
{
    ILogable i_Logable;
} NullObject;

void NullObject_Init(NullObject *const self);

#endif //SMELLS_NULLOBJECT_H
