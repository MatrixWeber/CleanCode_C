#include "address.h"
#include "console.h"
#include <stdio.h>
#include <string.h>

static void Address_ReadString(const char *const name, char *dest_string) {
    Print(name);
    const char *string = ReadString();
    strcpy(dest_string, string);
}

static void Address_ReadNumber(const char *const name, int *const number) { *number = ReadNumber("zip code"); }

static void Address_PrintString(const char *const name, const char *const string) {
    char tmp[MAX_TEXT_SIZE];
    sprintf_s(tmp, MAX_TEXT_SIZE, "%s: %s\n", name, string);
    Print(tmp);
}

static void Address_PrintCity(const Address *const self) {
    char tmp[MAX_TEXT_SIZE];
    sprintf_s(tmp, MAX_TEXT_SIZE, "City: %d %s\n", self->zip_code, self->city);
    Print(tmp);
}

void Address_Init(Address *const self) {
    self->city[0] = '\0';
    self->name[0] = '\0';
    self->street[0] = '\0';
    self->zip_code = 0;
}

void Address_Show(Address *const self) {
    Address_PrintString("Name", self->name);
    Address_PrintString("Street", self->street);
    Address_PrintCity(self);
    Print("\n");
}

void Address_Read(Address *const self) {
    Address_ReadString("Please enter the name: ", self->name);

    Address_ReadString("Please enter the street: ", self->street);
    Address_ReadNumber("zip code", &self->zip_code);

    Address_ReadString("Please enter the city: ", self->city);
    Print("\n");
}
