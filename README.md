## brainfuck-C
##### Ziemcorp Interactive COPYRIGHT ©2025
---
This is literally a brainfuck interpreter in C.

The greatest achievement in the history of achievements, maybe ever.

Size of the program is still **above** 10 bytes. <ins>We are learning.</ins>

For all esolang extremists: the best thing I could do is this 700 byte version (if you ignore the newlines)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char*argv[]){if(argc!=2)return 1;
int l=256,w;unsigned b[256],p=(l-1)/2,i=0;for(int i=0;i<256;i++)b[i]=0;while(i<strlen(argv[1])){
switch(argv[1][i]){
case'>':{p++;break;}
case'<':{p--;break;}
case'+':{b[p]=(b[p]+1)%(l+1);break;}
case'-':{b[p]=(b[p]-1)%(l+1);break;}
case',':{b[p]=getchar();break;}
case'.':{putchar(b[p]);break;}
case'[':{if(b[p]==0){w=1;while(i<=strlen(argv[1])&&w>0){i++;if(argv[1][i]==']')w--;else if(argv[1][i]=='[')w++;}}break;}
case']':{if(b[p]!=0){w=1;while(i>=0&&w>0){i--;if(argv[1][i]=='[')w--;else if(argv[1][i]==']')w++;}}break;}
}if(i<0||i>strlen(argv[1])||p<0||p>l)return 1;i++;}putchar(10);return 0;}
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
Imagine a simple brainfuck script:
```brainfuck
"examples/xkcd_random_number.bf"
+++++[>++++++++++<-]>++.#  ; appended symbol
```
Placing a # in any place will print out some information about the current situation:
```bash
./main "examples/xkcd_random_number.bf"
4 (output)
Instruction . at position 79
Cell value '4' (ASCII 52) at pointer value 1
```
#### 3. Examples
Programs I have written and put in the *examples* folder
1. Hello world - Everyone knows what a Hello world program does
2. Truth machine - Print a single '0' if input is '0', print '1' indefinitely if input is 1
3. XKCD random number - Return '4', based on XKCD page 221
#### 4. Windows support
Thinking about it.
