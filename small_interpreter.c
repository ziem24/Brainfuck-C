#include <stdio.h>

int main(int argc, char** argv) {
  int length = 30000, ptr = 0, pc = 0, w;
  unsigned char data[length], *code = argv[1];
  for (int i = 0; i < length; i++) data[i] = 0;

  while (code[pc]) {
    switch(code[pc]) {
      case '>' : { ptr++; break; }
      case '<' : { ptr--; break; }
      case '+' : { data[ptr]++; break; }
      case '-' : { data[ptr]--; break; }
      case ',' : { data[ptr] = getchar(); break; }
      case '.' : { putchar(data[ptr]); break; }
      case '[' : {
        if (!data[ptr]) {
          w = 1;
          while (w) {
            pc++;
            if (code[pc] == ']') w--;
            if (code[pc] == '[') w++;
          }
        }
        break;
      }
      case ']' : {
        if (data[ptr]) {
          w = 1;
          while (w) {
            pc--;
            if (code[pc] == '[') w--;
            if (code[pc] == ']') w++;
          }
        }
        break;
      }
    }
    pc++;
  }
  putchar('\n');
}