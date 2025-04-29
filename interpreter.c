// >	Increment the data pointer by one.
// <	Decrement the data pointer by one.
// +	Increment the byte at the data pointer by one.
// -	Decrement the byte at the data pointer by one.
// .	Output the byte at the data pointer.
// ,	Accept one byte of input, storing its value in the byte at the data pointer.
// [	If the byte at the data pointer is zero, then jump it forward to the command after the matching ] command.
// ]  If the byte at the data pointer is nonzero, then jump it back to the command after the matching [ command.
// #  Debugging method to print the data pointer location and the byte at the data pointer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findRightBracket(char* code, int leftBracketPos) {
  int weight = 1, indx = leftBracketPos;
  while(indx < strlen(code) && weight > 0) {
    indx++;
    if (code[indx] == ']') { weight--; }
    else if (code[indx] == '[') { weight++; }
  }
  return indx;
}

int findLeftBracket(char* code, int rightBracketPos) {
  int weight = 1, indx = rightBracketPos;
  while(indx > 0 && weight > 0) {
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
  int buf[256], ptr = 127, instr = 0;
  for(int i=0; i<256; i++) { buf[i] = 0; }

  for(int instr=0; instr<strlen(argv[1]); instr++) {
    switch (argv[1][instr]) {
      case '>': {
        ptr++;
        if (ptr > 255) {
          printf("Pointer out of range (>255)\n");
          return 2;
        }
        break;
      }
      case '<': {
        ptr--;
        if (ptr < 0) {
          printf("Pointer out of range (<0)\n");
          return 2;
        }
        break;
      }
      case '+': {
        buf[ptr] = (buf[ptr] + 1) % 256;
        break;
      }
      case '-': {
        buf[ptr]--;
        if (buf[ptr] < 0) { buf[ptr] = 255; }
        break;
      }
      case ',': {
        buf[ptr] = getchar();
        break;
      }
      case '.': {
        printf("%c", buf[ptr]);
        break;
      }
      case '[': {
        if (buf[ptr] == 0) { instr = findRightBracket(argv[1], instr); }
        break;
      }
      case ']': {
        if (buf[ptr] != 0) { instr = findLeftBracket(argv[1], instr); }
        break;
      }
      case '#': {
        printf("\nInstruction %c at position %d\n", argv[1][instr - 1], instr - 1);
        printf("Cell value %d at pointer value %d\n", buf[ptr], ptr - 127);
        break;
      }
      default : {
        break;
      }
    }
  }
  printf("\n");
  return 0;
}