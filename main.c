#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 30000

char* readFile(char* filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Could not read file \"%s\"\n", filename);
    return NULL;
  }

  fseek(file, 0L, SEEK_END);
  char* code = malloc(ftell(file) + 1);
  rewind(file);

  int currentChar, i = 0;
  while ((currentChar = fgetc(file)) != EOF) {
    code[i] = currentChar;
    i++;
  }
  fclose(file);
  return code;
}

int getRightBracket(char* code, int leftBracketPos) {
  int weight = 1, indx = leftBracketPos;
  while(code[indx] && weight > 0) {
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
  unsigned char buffer[BUFFER_SIZE];
  unsigned ptr = 0, instr_ptr = 0;
  for(int i=0; i<BUFFER_SIZE; i++) { buffer[i] = 0; }
  char* code = readFile(argv[1]);
  if (code == NULL) { return 2; }

  while(code[instr_ptr]) {
    switch (code[instr_ptr]) {
      case '>': { ptr++; break; }
      case '<': { ptr--; break; }
      case '+': { buffer[ptr]++; break; }
      case '-': { buffer[ptr]--; break; }
      case ',': { buffer[ptr] = getchar(); break; }
      case '.': { putchar(buffer[ptr]); break; }
      case '[': { if (buffer[ptr] == 0) instr_ptr = getRightBracket(code, instr_ptr); break; }
      case ']': { if (buffer[ptr] != 0) instr_ptr = getLeftBracket(code, instr_ptr); break; }
      case '#': {
        printf("\nInstruction %c at position %d\n", code[instr_ptr - 1], instr_ptr - 1);
        printf("Cell value '%c' (%d) at pointer value %d\n", buffer[ptr], buffer[ptr], ptr);
        break;
      }
      default : { break; }
    }
    if (instr_ptr < 0 || !code[instr_ptr]) {
      printf("Program counter out of range (%d)\n", instr_ptr);
      return 3;
    }
    if (ptr < 0 || ptr > BUFFER_SIZE) {
      printf("Instruction pointer out of range (%d)\n", ptr);
      return 4;
    }
    instr_ptr++;
  }
  printf("\n");
  return 0;
}