#include "tests.h"
#include <stdbool.h>
#include <string.h>
#include "../../test_framework/test_functions.h"
#include "address_management.h"

#define MAX_BUFFER_SIZE 256

void AddAddress(FILE* stream, const char* name, const int zip_code)
{
  fprintf(stream, "%s_a\n", name);
  fprintf(stream, "%s_b\n", name);
  fprintf(stream, "%d", zip_code);
  fprintf(stream, "%s_c\n", name);
}

void PrepareAdresses(FILE* stream, const int number)
{
  char buffer[2];
  char start_name = 'a';
  int start_number = 1;
  for (int i = 0; i < number; ++i) {
    buffer[0] = start_name;
    buffer[1] = '\0';
    AddAddress(stream, buffer, start_number);
    ++start_number;
    ++start_name;
  }
}

bool Search(FILE* output, const char* search_string)
{
  char line[MAX_BUFFER_SIZE];
  fgets(line, MAX_BUFFER_SIZE, output);
  const char* found = strstr(line, search_string);

  if (found == NULL) {
    printf("Error: %s not found\n", search_string);
    return false;
  }

  return true;
}

bool CheckPart(FILE* output, const char* name, const char* suffix)
{
  char search_string[MAX_BUFFER_SIZE];
  sprintf(search_string, "%s%s", name, suffix);

  return Search(output, search_string);
}

bool CheckIntegerPart(FILE* output, const int zip_code)
{
  char search_string[MAX_BUFFER_SIZE];
  sprintf(search_string, "%d", zip_code);

  return Search(output, search_string);
}

bool CheckAdress(FILE* output, const char* name, const int zip_code)
{
  bool result = CheckPart(output, name, "_a");
  result = CheckPart(output, name, "_b") && result;
  result = CheckIntegerPart(output, zip_code) && result;
  result = CheckPart(output, name, "_c") && result;

  return result;
}

bool CheckAdresses(FILE* output, const int number)
{
  char buffer[2];
  char start_name = 'a';
  int start_number = 1;
  bool result = true;

  for (int i = 0; i < number; i++) {
    buffer[0] = start_name;
    buffer[1] = '\0';
    result = CheckAdress(output, buffer, start_number) && result;

    ++start_number;
    ++start_name;
  }

  return result;
}

TEST(TestAddressManagementInit)
{
  const int expected = 3;
  AddressManagement management;
  AddressManagement_Init(&management, expected);
  ASSERT(AddressManagement_GetNumberOfAddresses(&management) == expected,
         "AddressManagement initialization failed");
}

TEST(TestAddressManagementReadWrite)
{
  const int number_of_addresses = 3;

  AddressManagement management;
  AddressManagement_Init(&management, number_of_addresses);

  FILE* input = fopen("input.txt", "w");
  PrepareAdresses(input, AddressManagement_GetNumberOfAddresses(&management));
  fclose(input);

  input = freopen("input.txt", "r", stdin);
  FILE* trash = freopen("trash.txt", "w", stdout);

  AddressManagement_ReadAllAddresses(&management);

  fclose(input);
  fclose(trash);
  freopen("CON", "r", stdin);

  FILE* output = freopen("output.txt", "w", stdout);
  AddressManagement_WriteAllAddresses(&management);

  fclose(output);

#ifdef __linux__
  freopen("/dev/tty", "a", stdout);
#elif _WIN32
  freopen("CON", "a", stdout);
#else
#endif

  output = fopen("output.txt", "r");
  const bool result = CheckAdresses(
      output, AddressManagement_GetNumberOfAddresses(&management));
  ASSERT(result, "Address read/write failed");
}

TEST_SUITE(TestAddressManagement)
{
  RUN_TEST(TestAddressManagementInit);
  RUN_TEST(TestAddressManagementReadWrite);
}

void RunTests() { RUN_TEST_SUITE(TestAddressManagement); }
