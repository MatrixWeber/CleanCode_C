#ifndef ADDRESS_H
#define ADDRESS_H

#define MAX_TEXT_SIZE 256

typedef struct Address_ {
  char name[MAX_TEXT_SIZE];
  char street[MAX_TEXT_SIZE];
  char city[MAX_TEXT_SIZE];
  int zip_code;
} Address;

void Address_Init(Address* self);
void Address_Write(const Address* self);

#endif  // ADDRESS_H
