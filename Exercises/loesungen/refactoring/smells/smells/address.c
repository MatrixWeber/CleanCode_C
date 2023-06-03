#include "address.h"
#include <stdbool.h>
#include <stdio.h>

void Address_Init(Address* self)
{
  self->city[0] = '\0';
  self->name[0] = '\0';
  self->street[0] = '\0';
  self->zip_code = 0;
}

// der Name ist nicht eindeutig vielleicht besser: Address_Show
void Address_Write(Address* self)
{
  printf("Name: %s\n", self->name);
  printf("Street: %s\n", self->street);
  printf("City: %d %s\n", self->zip_code, self->city);
}

// Zu lange Funktion
void Address_Read(Address* self)
{
  // Code wiederholt sich, Einlesen eines Textes könnte in ein separates File
  // ausgelagert werden
  printf("Please enter the name: ");
  scanf("%s", self->name);

  printf("Please enter the street: ");
  scanf("%s", self->street);

  // Einlesen einer Zahl könnte in ein separates File ausgelagert werden
  // Wiederholung von main()
  while (true) {
    printf("Please enter the zip code: ");

    const int items = scanf("%d", &self->zip_code);

    if (items > 0) {
      break;
    }

    printf("Please enter a number\n");
    char temp;
    while ((temp = fgetc(stdin)) != EOF) {
      if (temp == '\n') {
        break;
      }
    }
  }

  printf("Please enter the city: ");
  scanf("%s", self->city);
}

// Auch wenn es erst einmal objektorientiert aussieht, wäre es besser die
// Funktionen zum Einlesen und Ausgeben extern zu implementieren, um die
// Abhängigkeit der Datenklasse vom Ausgabemedium zu entfernen