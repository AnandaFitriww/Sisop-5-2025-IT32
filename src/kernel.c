#include "shell.h"
#include "kernel.h"

int main() {
  clearScreen();
  shell();
}

void printString(char *str)
{
  while (*str != 0) {
    __asm__ volatile(
      "mov $0x0E, %%ah \n"  
      "mov %0, %%al \n"
      "int $0x10"
      :
      : "r" (*str)
    );
    str++;
  }
}

void readString(char *buf)
{
  int i = 0;
  char c = 0;

  while (1) {
    __asm__ volatile(
      "mov $0x00, %%ah \n"  
      "int $0x16 \n"
      "mov %%al, %0"
      : "=r" (c)
      :
      : "ah", "al"
    );

    if (c == 13 || c == 10) {
      break;
    } else if (c == 8) {
      if (i > 0) {
        i--;
        printString("\b \b");
      }
    } else {
      buf[i++] = c;
      __asm__ volatile(
        "mov $0x0E, %%ah \n"
        "mov %0, %%al \n"
        "int $0x10"
        :
        : "r" (c)
      );
    }
  }
  buf[i] = '\0'; 
  printString("\n");
}

void clearScreen()
{

printString("\033[2J\033[H");
}
