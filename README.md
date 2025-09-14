## brainfuck-C
##### Ziemcorp Interactive COPYRIGHT ©2025
---
This is literally just a brainfuck interpreter in C.

The greatest achievement in the history of achievements, maybe ever.

Size of the program is still **above** 10 bytes. <ins>We are learning.</ins>

For all esolang extremists: the best thing I could do is this 440 byte version (if you ignore the newlines).
This version has exceptions handled by the operating system among many other cutting-~~edge~~corner technologies.
If you run some faulty code on a PDP-8 or other old thing it may just nuke your computer.
```c
#include<stdio.h>
#define B break;
main(int argc,char**argv){
  int l=30000,p=0,i=0,w;
  unsigned char b[l],*a=argv[1];
  for(int i=0;i<l;i++)b[i]=0;
  while(a[i]){
    switch(a[i]){
      case'>':{p++;B;}
      case'<':{p--;B;}
      case'+':{b[p]++;B;}
      case'-':{b[p]--;B;}
      case',':{b[p]=getchar();B;}
      case'.':{putchar(b[p]);B;}
      case'[':{if(!b[p]){w=1;while(w){i++;if(a[i]==93)w--;if(a[i]==91)w++;}}B;}
      case']':{if(b[p]){w=1;while(w){i--;if(a[i]==91)w--;if(a[i]==93)w++;}}B;}
    }i++;}}
```

---
#### 1. Running the program
To start, download the files and run a brainfuck file like this:
```bash
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
Cell value '4' (ASCII 52) at pointer value 1
```
which means that the comments or anything else should not contain hashtags!!!

#### 3. Examples
Programs I have written and put in the *examples* folder
1. Hello world - Everyone knows what a Hello world program does
2. Truth machine - Print a single '0' if input is '0', print '1' indefinitely if the input is '1'
3. XKCD random number - Return '4', based on XKCD page 221
4. 6 times 8 - returns a product of two values already in cells; preserves the multiplicand
5. If-else - If-else statement
6. Cat - A cat program that terminates after a single use
7. Test - No idea what it does. Not trying it either.
#### 4. small_interpreter.c and unreadable_interpreter.c
Those are bonus interpreters using system arguments for code input. They are also meant to see how small can these interpreters get.
They can be compiled using `make NAME=small_interpreter` or `make NAME=unreadable_interpreter`. These files can be executed with the command `./main "piece of code"`.
#### 5. Windows support
Thinking about it.