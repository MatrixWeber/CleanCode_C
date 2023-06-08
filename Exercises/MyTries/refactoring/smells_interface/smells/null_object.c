//
// Created by SW on 08.06.2023.
//

#include <stdio.h>
#include "null_object.h"

int NullObject_ReadNumber(const char *const name) {
    NullObject_Print("Not implemented\n");
    return 1;
}

void NullObject_Print(const char *text) {
    printf("%s", text);
}

const char *NullObject_ReadString() {
    const char *text = "Not implemented\n";
    NullObject_Print(text);
    return text;
}