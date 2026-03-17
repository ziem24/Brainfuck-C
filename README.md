## brainfuck-C: Boolean
##### Ziemcorp Interactive COPYRIGHT ©2025-2026
---
This is a small experiment. This Brainfuck alternative adds a small twist to the original one.
- Every cell is a 1-bit value
- `+` and `-` have been replaced b y `^`, which is equivalent to bit negation (or XOR-ing by 1)
- `.` prints out the cell value, not its ASCII encoding
- `,` fetches the least significant bit of a character

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
^.^..#  ; appended symbol
```
will print out some useful information (instruction/data pointer location, cell value)
```sh
./main examples/xkcd_random_number.bf
100
Instruction . at position 60
Cell value 0 at pointer value 0
```
which means that the comments or anything else should not contain hashtags!!!

#### 3. Examples
Programs I have written and put in the *examples* folder
1. Truth machine - Print a single '0' if input is '0', print '1' indefinitely if the input is '1'
2. XKCD random number - Return '4', based on XKCD page 221
3. If-else - An if-else statement
4. Cat - A cat program that terminates on the first 0