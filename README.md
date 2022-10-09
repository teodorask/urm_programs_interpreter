# urm_programs_interpreter
## The URM (unlimited register machine)
An URM is an abstract machine with unlimited memory. 
Machine memory is represented by an infinite array of natural numbers m[0], m[1], . . ., where m[i] ∈N . 
We call the elements of the array "cells" of the machine's memory, 
and the number i the "address" of the cell m[i].

The memory is implemented via a sparse array, which is implemented via unordered_map.

## Programs for URM
The programs are numbered (from 0) lists of operators - instructions and commands.
### Instructions:
- ZERO n      - the value of cell n becomes 0
- INC n       - increments the value of cell n
- MOVE x y    - the value of cell y is changed to that of cell x
- JUMP z      - the program continues from line z; if there are less than z+1 lines, the program ends
- JUMP x y z  - if the values in cells x and y are the same, the program goes to line z (if there are less than z+1 lines, 
the program ends), otherwise it goes to the next line 

### Commands:
- /zero x y - assigns 0 to cells from x to y ([x, y])
- /set x y - assigns y as the value of cell x
- /copy x y z - copies the values of cells [x, x+z-1] into cells [y, y+z-1]
- /mem x y - prints the values of cells [x, y]
- /load <filename> - loads a new program from a text file; the previous program and memory are erased
- /run - executes the current program
- /add <filename> - appends the program from <filename> to the end of the current program
- /quote <string> - appends a new operator to the end of the current program
- /code - prints the current program
- /comment <string> - adds a comment to the program; has no effect on execution

## Example Programs 
- add.urm - adds the values of cells 0 and 1; the result is stored in cell 3
- fib.urm - calculates the nth number of Fibonacci, where n is the value of celll 0 and the result is stored in cell 1
