#include <stdint.h>
#include "application.h"
#include "console.h"
#include "disk.h"

int main() {
    Console console;
    Console_Init(&console);
    ILogable* terminal = &console.i_Logable;  // set to NULL show the Null Object Pattern;
    Disk disk;
    Disk_Init(&disk, "smell.txt", terminal);
    ILogable* logable = &disk.i_Logable;
    int number_of_addresses = logable->readNumber("number of addresses");

    Application application;
    Application_Init(&application, number_of_addresses, logable);

    application.run();

    return 0;
}
