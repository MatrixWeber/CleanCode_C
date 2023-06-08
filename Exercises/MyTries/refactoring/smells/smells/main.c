#include "application.h"
#include "console.h"

int main() {
    int number_of_addresses = ReadNumber("number of addresses");

    Application application;
    Application_Init(&application, number_of_addresses);

    application.run();

    return 0;
}
