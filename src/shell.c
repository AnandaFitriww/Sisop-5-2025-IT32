#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

void shell() {
  char buf[128];
  printString("Welcome to EorzeOS!\n");
  while (true) {
    printString("> ");
    readString(buf);

    if (strcmp(buf, "yo")) {
      printString("gurt\n");
    } else if (strcmp(buf, "gurt")) {
      printString("yo\n");
    } else {
      printString(buf);
      printString("\n");
    }
  }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  //TODO: Implementasi fungsi untuk mem-parsing perintah
}

// Tambahkan fungsi bila perlu
