#include <stdio.h>
#include <features.h>

int main(void) {
  printf("__GLIBC__       %u\n", __GLIBC__);
  printf("__GLIBC_MINOR__ %u\n", __GLIBC_MINOR__);
  return 0;
}