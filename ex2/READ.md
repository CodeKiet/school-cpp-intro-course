# Exercise #1 Read Me

  This exercise is divided into 4 seperate and unrelated programs:
  1. ex1_a
  2. ex1_b
  3. ex1_c
  4. ex1_d

ex1_a
=====
### Program Overview:
	Get 20 numbers from user and output lines split
	by ascending and descending lines on each new line.
	prints a summary at the end that summarizes how many lines of each there were.

### Source code:
```
ex1_a.c
```

### Functions:
```
main(void)
```

### Input:
	User must input 20 numbers seperated by spaces and press enter at the end
	for program to process the numbers

### Output:
	prints to console the seperated lines + a summary

### Compile:
```
gcc -o ex1_a ex1_a.c
```
### Run:
```
./ex1_a
```





ex1_b:
===========
### Program Overview:
	Program takes sets of 2 integers at a time until reaches the set 0 0.
	After each set the program will print how many digits of the first integer
	were present in the second (we are assuming all digits are 10 digits or less)

### Source code:
```
ex1_b.c
```

### Functions:
```
main(void)
int pairCount(int a, int b)  // counts of how many digits of first int are in second int
int digitInNum(int digit, int num) // if digit is in num returns 1, otherwise 0
```

### Input:
	Enter pair of 2 integers seperated by a space.
	When finished, enter 0 0 to exit.

### Output:
	After each pair of 2 integers a digit count will be printed to console

### Compile:
```
gcc -o ex1_b ex1_b.c
```
### Run:
```
./ex1_b
```



ex1_c:
===========
### Program Overview:
	Program reads list of integers from user until reaches -1
	After each number it checks whether the number is the same as the
	average of all the previous numbers, if so, it prints it with it's
	current place in the list.
	At the end, the program prints how many of these "special numbers"
	were printed in total.

### Source code:
```
ex1_c.c
```

### Functions:
```
main(void)

```

### Input:
	Reads list of integers seperated by spaces given by the user.
	Input -1 to exit.

### Output:
	After each integer that is "special" program will print to console output.
	At the end of the program (user entered -1) will print to console again a total.

### Compile:
```
gcc -o ex1_c ex1_c.c
```
### Run:
```
./ex1_c
```


ex1_d:
===========

### Program Overview:
	This program generates 10 random numbers and prints their
	palindromes based on this specification:
		1. If the number is a palindrome already: prints it
		2. Reverses the number and attaches the reversed number to the end (Thus creating a palindrome)

### Source code:
```
ex1_d.c
```

### Functions:
```
main(void)
int digits(int) // returns amount of digits of any positive integer
```

### Input:
	None.

### Output:
	prints to console a List of 10 randomly generated palindromes based on specification

### Compile:
```
gcc -o ex1_d ex1_d.c
```
### Run:
```
./ex1_d
```
