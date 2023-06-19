#include "address.h"
#include <stdio.h>
#include <string.h>

static Address* this;

static void Address_ReadString(const char *const name, char *dest_string) {
    this->i_logable->print(name);
    const char *string = this->i_logable->readString();
    strcpy(dest_string, string);
}

static void Address_ReadNumber(const char *const name, int *const number) { *number = this->i_logable->readNumber("zip code"); }

static void Address_PrintString(const char *const name, const char *const string) {
    char tmp[MAX_NAME_SIZE];
    sprintf_s(tmp, MAX_NAME_SIZE, "%s: %s\n", name, string);
    this->i_logable->print(tmp);
}

static void Address_PrintCity(const Address *const self) {
    char tmp[MAX_NAME_SIZE];
    sprintf_s(tmp, MAX_NAME_SIZE, "City: %d %s\n", self->zip_code, self->city);
    self->i_logable->print(tmp);
}

static void Address_Show() {
    Address_PrintString("Name", this->name);
    Address_PrintString("Street", this->street);
    Address_PrintCity(this);
    this->i_logable->print("\n");
}

static void Address_Read() {
    Address_ReadString("Please enter the name: ", this->name);

    Address_ReadString("Please enter the street: ", this->street);
    Address_ReadNumber("zip code", &this->zip_code);

    Address_ReadString("Please enter the city: ", this->city);
    this->i_logable->print("\n");
}

void Address_Init(Address *const self, ILogable *const i_logable) {
    this = self;
    self->i_logable = i_logable;
    self->city[0] = '\0';
    self->name[0] = '\0';
    self->street[0] = '\0';
    self->zip_code = 0;
    self->addressRead = Address_Read;
    self->addressShow = Address_Show;
}
