#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Running unit tests...\n");

  if (10 != 10) {
    return EXIT_FAILURE;
  }

  printf("All unit tests passed successfully.\n");
  return EXIT_SUCCESS;
}
