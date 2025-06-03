#include "std_lib.h"

int div(int a, int b)
{
  
}

int mod(int a, int b)
{

}

bool strcmp(char *str1, char *str2)
{
  while (*str1 && *str2) {
    if (*str1 != *str2) return false;
    str1++;
    str2++;
  }
  return (*str1 == '\0' && *str2 == '\0');
}

void strcpy(char *dst, char *src)
{
  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';
}

void clear(byte *buf, unsigned int size)
{
  for (unsigned int i = 0; i < size; i++) {
    buf[i] = '\0';
  }
}

void atoi(char *str, int *num)
{

}

void itoa(int num, char *str)
{

}
