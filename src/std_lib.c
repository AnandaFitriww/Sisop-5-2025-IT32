#include "std_lib.h"

int div(int a, int b)
{
  // Belum diperlukan untuk soal no 2
}

int mod(int a, int b)
{
  // Belum diperlukan untuk soal no 2
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
  // Belum diperlukan untuk soal no 2
}

void clear(byte *buf, unsigned int size)
{
  // Belum diperlukan untuk soal no 2
}

void atoi(char *str, int *num)
{
  // Belum diperlukan untuk soal no 2
}

void itoa(int num, char *str)
{
  // Belum diperlukan untuk soal no 2
}
