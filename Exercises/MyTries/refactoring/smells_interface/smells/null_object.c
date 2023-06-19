//
// Created by SW on 08.06.2023.
//

#include <stdio.h>
#include "null_object.h"

static void NullObject_Print(const char *const text) {
    printf("%s", text);
}

static int NullObject_ReadNumber(const char *const name) {
    NullObject_Print("Not implemented\n");
    return 1;
}

static const char *NullObject_ReadString() {
    const char *text = "Not implemented\n";
    NullObject_Print(text);
    return text;
}


void NullObject_Init(NullObject *const self) {
    self->i_Logable.print = NullObject_Print;
    self->i_Logable.readNumber = NullObject_ReadNumber;
    self->i_Logable.readString = NullObject_ReadString;
}