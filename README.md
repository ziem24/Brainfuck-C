## brainfuck-C
##### Ziemcorp Interactive COPYRIGHT ©2025-2026
---
This is literally just a brainfuck interpreter in C.

The greatest achievement in the history of achievements, maybe ever.

Size of the program is still **above** 10 bytes. <ins>We are learning.</ins>

For all esolang extremists: the best thing I could do is this 349 byte version (if you ignore the newlines and indents).
This version has exceptions handled by the operating system among many other cutting-~~corner~~edge technologies.
This thing needs to be smitten.
```c
#include<stdio.h>
#define B ;break;}case
#define D (a[i]==91)-(a[i]==93);
int main(int c,char**v){
  int l=30000,p=0,i=0,w;
  char b[l],*a=v[1];
  for(int i=0;i<l;i++)b[i]=0;while(a[i]){
    w=1;
    switch(a[i]){
      case'>':{p++
      B'<':{p--B'+':{b[p]++
      B'-':{b[p]--
      B',':{b[p]=getchar()
      B'.':{putchar(b[p])
      B'[':{while(w){i++;w+=D}i--
      B']':{while(b[p]&&w){i--;w-=D}break;}}
    i++;
  }
}
```

---
#### 1. Running the program
To start, download the files and run a brainfuck file like this:
```sh
cd path/to/repository
make
./main "path/to/file"
```

#### 2. Debugging
Placing a hashtag in any place like this:
```brainfuck
"examples/xkcd_random_number.bf"
+++++[>++++++++++<-]>++.#  ; appended symbol
```
will print out some useful information (instruction/data pointer location, cell value)
```bash
./main "examples/xkcd_random_number.bf"
4 (output)
Instruction . at position 79
Cell value '4' (52) at pointer value 1
```
which means that the comments or anything else should not contain hashtags!!!

#### 3. Examples
Programs I have written and put in the *examples* folder
1. Hello world - Everyone knows what a Hello world program does
2. Truth machine - Print a single '0' if input is '0', print '1' indefinitely if the input is '1'
3. XKCD random number - Return '4', based on XKCD page 221
4. 6 times 8 - returns a product of two values already in cells; preserves the multiplicand
5. If-else - An if-else statement
6. Cat - A cat program that terminates after a single use
7. Test - No idea what it does. Not trying it either.
8. Nested brackets - tests if the program correctly handles nested brackets
#### 4. small_interpreter.c and unreadable_interpreter.c
Those are bonus interpreters using system arguments for code input. They are also meant to see how small can these interpreters get.
They can be compiled using `make NAME=small_interpreter.c` or `make NAME=unreadable_interpreter.c`. The Brainfuck programs can be executed with the command `./main "piece of code"`.
#### 5. Windows support
Thinking about it.