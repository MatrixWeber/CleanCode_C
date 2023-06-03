#include <stdio.h>
#include "counter_app.h"
#include "tests.h"

int main()
{
  UseCounter(stdout);

  RunTests();

  return 0;
}
