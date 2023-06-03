//
// Created by SW on 03.06.2023.
//

#ifndef DRY_DISK_H
#define DRY_DISK_H

#define MAX_STRING_SIZE 256

typedef struct
{
    char file_name[MAX_STRING_SIZE];
} Disk;

void Disk_Init(Disk *const self, const char file_name[MAX_STRING_SIZE]);
void Disk_Write(Disk *const self, const char* text);

#endif //DRY_DISK_H
