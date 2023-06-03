//
// Created by SW on 03.06.2023.
//

#include <string.h>
#include <stdio.h>
#include "disk.h"
#include "console.h"

void Disk_Init(Disk *const self, const char file_name[MAX_STRING_SIZE])
{
    strcpy_s(self->file_name, MAX_STRING_SIZE, file_name);
}

void Disk_Write(Disk *const self, const char* text)
{
    FILE *file;
    errno_t err = fopen_s(&file, self->file_name, "a");
    if(err != 0)
    {
        Console_Write("File not opened");
        return;
    }
    fprintf(file, "%s", text);
    fclose(file);
}
