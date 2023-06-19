//
// Created by SW on 08.06.2023.
//

#include <stdio.h>
#include <string.h>
#include "disk.h"

static Disk *this;

static void WriteToFile(const char *text);

static void WriteToFile(const char *text) {
    FILE *file;
    errno_t err = fopen_s(&file, this->file_name, "a");
    if (!err) {
        fprintf(file, "%s %c", text, '\n');
        fclose(file);
    }
}

static int readNumber(const char *const name) {
    const int number = this->console->readNumber(name);
    char str[50];
    sprintf(str, "%s: %d", name, number);
    WriteToFile(str);
    return number;
}

static void print(const char *const text) {
    this->console->print(text);
    WriteToFile(text);
}

static const char *readString() {
    const char* str = this->console->readString();
    WriteToFile(str);
    return str;
}

void Disk_Init(Disk *const self, const char *const file_name, ILogable *const console) {
    this = self;
    self->console = console;
    self->logable.print = print;
    self->logable.readNumber = readNumber;
    self->logable.readString = readString;
    strcpy(self->file_name, file_name);
}
