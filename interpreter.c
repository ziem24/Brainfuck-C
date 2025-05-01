#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256

char* readFile(char* filename) {

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Could not read file \"%s\"\n", filename);
    return NULL;
  }

  fseek(file, 0L, SEEK_END);
  char* script = malloc(ftell(file) + 1);
  rewind(file);

  int currentChar, i = 0;
  while ((currentChar = fgetc(file)) != EOF) {
    script[i] = currentChar;
    i++;
  }
  fclose(file);
  return script;
}

int getRightBracket(char* code, int leftBracketPos) {
  int weight = 1, indx = leftBracketPos;
  while(indx <= strlen(code) && weight > 0) {
    indx++;
    if (code[indx] == ']') { weight--; }
    else if (code[indx] == '[') { weight++; }
  }
  return indx;
}

int getLeftBracket(char* code, int rightBracketPos) {
  int weight = 1, indx = rightBracketPos;
  while(indx >= 0 && weight > 0) {
    indx--;
    if (code[indx] == '[') { weight--; }
    else if (code[indx] == ']') { weight++; }
  }
  return indx;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Wrong arguments, usage: ./main <code>\n");
    return 1;
  }
  unsigned buffer[BUFFER_SIZE], ptr = (BUFFER_SIZE-1)/2, instr_ptr = 0;
  for(int i=0; i<BUFFER_SIZE; i++) { buffer[i] = 0; }
  char* script = readFile(argv[1]);
  if (script == NULL) { return 2; }


  while(instr_ptr < strlen(script)) {
    switch (script[instr_ptr]) {
      case '>': {
        ptr++;
        break;
      }
      case '<': {
        ptr--;
        break;
      }
      case '+': {
        buffer[ptr] = (buffer[ptr] + 1) % BUFFER_SIZE;
        break;
      }
      case '-': {
        buffer[ptr] = (buffer[ptr] - 1) % BUFFER_SIZE;
        break;
      }
      case ',': {
        buffer[ptr] = getchar();
        break;
      }
      case '.': {
        putchar(buffer[ptr]);
        break;
      }
      case '[': {
        if (buffer[ptr] == 0) { instr_ptr = getRightBracket(script, instr_ptr); }
        break;
      }
      case ']': {
        if (buffer[ptr] != 0) { instr_ptr = getLeftBracket(script, instr_ptr); }
        break;
      }
      case '#': {
        printf("\nInstruction %c at position %d\n", script[instr_ptr - 1], instr_ptr - 1);
        printf("Cell value '%c' (ASCII %d) at pointer value %d\n", buffer[ptr], buffer[ptr], ptr - (BUFFER_SIZE - 1)/2);
        break;
      }
      default : {
        break;
      }
    }
    if (instr_ptr < 0 || instr_ptr > strlen(script)) {
      printf("Program counter out of range (%d)\n", instr_ptr);
      return 3;
    }
    if (ptr < 0 || ptr > BUFFER_SIZE) {
      printf("Pointer out of range (%d)\n", ptr);
      return 4;
    }
    instr_ptr++;
  }
  printf("\n");
  free(script);
  return 0;
}