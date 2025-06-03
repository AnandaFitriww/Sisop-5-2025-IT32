#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

void shell() {
  char buf[128];
  char username[64] = "user";
  char command[16];
  char args[2][64];

  printString("Welcome to EorzeOS!\n");

  while (true) {
    printString(username);
    printString("> ");
    readString(buf);

    parseCommand(buf, command, args);

    if (strcmp(command, "user")) {
      if (args[0][0] == '\0') {
        strcpy(username, "user");
        printString("Username changed to user\n");
      } else {
        strcpy(username, args[0]);
        printString("Username changed to ");
        printString(username);
        printString("\n");
      }
    }
    else if (strcmp(command, "yo")) {
      printString("gurt\n");
    }
    else if (strcmp(command, "gurt")) {
      printString("yo\n");
    }
    else {
      printString(buf);
      printString("\n");
    }
  }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  int i = 0, j = 0, k = 0;
  clear(arg[0], 64);
  clear(arg[1], 64);

  while (buf[i] != ' ' && buf[i] != '\0') {
    cmd[i] = buf[i];
    i++;
  }
  cmd[i++] = '\0';

  if (buf[i] != '\0') {
    while (buf[i] != ' ' && buf[i] != '\0') {
      arg[0][j++] = buf[i++];
    }
    arg[0][j] = '\0';
  }

  if (buf[i] != '\0') {
    i++;
    while (buf[i] != ' ' && buf[i] != '\0') {
      arg[1][k++] = buf[i++];
    }
    arg[1][k] = '\0';
  }
}
