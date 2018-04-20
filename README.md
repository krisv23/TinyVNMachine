# TinyVNMachine
### Simulates a Tiny Von Neumann Machine

### Getting started
 This program was built with C. In order to have the machine perform operations, you must pass it a text file that meets the Von Neumann Architecture. I have included this Architecture below.


### Instruction Set Architecture

```
Instruction Set Architecture: 
1  LOAD  -- Loads data from the Data Memory
2  ADD   -- Addition Function that performs addition on the value in the accumulator with a value specified inside the Data Memory.
3  STORE -- Stores the accumulator into Data Memory.
4  SUB   -- Subtract function that perfroms subtraction on the value in the accumulator with a value specified inside the Data Memory.
5  IN    -- Collects input from the keyboard. 
6  OUT   -- Displays output to the monitor.
7  END   -- Terminates Program.
8  JMP   -- Jumps to the specified operation.
9  SKIPZ -- Skips the next operation if the accumulator == 0.
```


### Input File example
Below is an example of an input file that subtracts two numbers. Please make sure input file is a .txt extension.
	
 ``` 
  The first number is the operation and the second number is the address. 
	Input File:
	    5 5		//IN 5   <-- Input from address 5 (keyboard)
	    6 7		//OUT 7  <-- Output to address 7 (monitor)
	    3 0		//STORE 0 <-- Store accumulator into Data Memory at address 0
	    5 5		//IN 5    <-- Input from address 5 (keyboard)
	    6 7		//OUT 7   <-- Output to address 7 (monitor)
	    3 1		//STORE 1 <-- Store accumulator into Data Memory at address 1
	    1 0		//LOAD 0  <-- Load into accumulator the value in Data Memory at address 0
	    4 1		//SUB 1   <-- Subtract accumulator from the value in Data Memory at address 1
	    3 0		//STORE 0 <-- Store accumulator into Data Memory at address 0
	    6 7		//OUT 7   <-- Output to address 7 (monitor)
	    7 0		//END     <-- Halt program
```
