#include <stdint.h>
#include "application.h"
#include "console.h"
#include "disk.h"
#include "null_object.h"

int main() {
    Console console;
    Console_Init(&console);
    ILogable* terminal = &console.i_Logable;  // set to NULL show the Null Object Pattern;
    if(terminal == NULL)
    {
        static NullObject nullObject;
        NullObject_Init(&nullObject);
        terminal = &nullObject.i_Logable;
    }
//    Disk disk;
//    Disk_Init(&disk, "a.txt", terminal);
//    ILogable* file_writer = &disk.logable;
    int number_of_addresses = terminal->readNumber("number of addresses");

    Application application;
    Application_Init(&application, number_of_addresses, terminal);

    application.run();

    return 0;
}
