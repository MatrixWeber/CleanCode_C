#include <stdio.h>
#include "tests.h"
#include "counter_app.h"

int main()
{
  UseCounter(stdout);

  RunTests();

  return 0;
}
