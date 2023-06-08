//
// Created by SW on 08.06.2023.
//

#include <stdio.h>
#include <string.h>
#include "disk.h"
#include "null_object.h"

static Disk *this;

static void WriteToFile(const char *text);

static void register_this(Disk *const self) {
    this = self;
}

static void WriteToFile(const char *text) {
    FILE *file;
    errno_t err = fopen_s(&file, this->file_name, "a");
    if (!err) {
        fprintf(file, "%s %c", text, '\n');
        fclose(file);
    }
}

static int ReadNumber(const char *const name) {
    const int number = this->console->readNumber(name);
    char str[50];
    sprintf(str, "%s: %d", name, number);
    WriteToFile(str);
    return number;
}

static void Print(const char *text) {
    this->console->print(text);
    WriteToFile(text);
}

static const char *ReadString() {
    const char* str = this->console->readString();
    WriteToFile(str);
    return str;
}

static void CreateAndRegisterNullObjet(Disk *const self) {
    static ILogable null_object;
    self->console = &null_object;
    self->console->print = NullObject_Print;
    self->console->readNumber = NullObject_ReadNumber;
    self->console->readString = NullObject_ReadString;
}

void Disk_Init(Disk *const self, const char *const file_name, ILogable *const console) {
    self->register_this = register_this;
    self->register_this(self);
    self->i_Logable.print = Print;
    self->i_Logable.readNumber = ReadNumber;
    self->i_Logable.readString = ReadString;
    strcpy(self->file_name, file_name);
    if(console)
    {
        self->console = console;
    }
    else
    {
        CreateAndRegisterNullObjet(self);
    }
}
