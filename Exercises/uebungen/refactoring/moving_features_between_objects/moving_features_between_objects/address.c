#include "address.h"
#include <stdio.h>

void Address_Init(Address* self)
{
  self->city[0] = '\0';
  self->name[0] = '\0';
  self->street[0] = '\0';
  self->zip_code = 0;
}

void Address_Write(const Address* self)
{
  printf("Name: %s\n", self->name);
  printf("Street: %s\n", self->street);
  printf("Zip code: %d\n", self->zip_code);
  printf("City: %s\n", self->city);
}
