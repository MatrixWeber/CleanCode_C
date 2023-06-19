//
// Created by SW on 08.06.2023.
//

#ifndef SMELLS_DISK_H
#define SMELLS_DISK_H

#include "i_logable.h"

#define MAX_FILE_NAME_SIZE 100

typedef struct
{
    char file_name[MAX_FILE_NAME_SIZE];
    ILogable* console;
    ILogable logable;
} Disk;

void Disk_Init(Disk *const self, const char *const file_name, ILogable *const console);

#endif //SMELLS_DISK_H
