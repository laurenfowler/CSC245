1. The goal of the client progragm is to act as a Reverse Polish Notation calculator. It should be able to handle
	operations such as printin, clearing, duplicating, reversing, addition, subtraction, multiplication, division,
	and remainder

2. Input is read in from the keyboard and output is sent to the console by calling the p, n, and f operations.

3. Classes used by this program include the stack and string class. The stack class has methods such as pop, push, 
	size, and empty. The string class includes functions such as finding a substring, appending characters, 
	erasing, and inserting characters into strings
4.
	The input will need to be parsed, so that even values entered without spaces will be understood 
		and the calucluator will perform as it would if there were spaces. The program should have
		a try catch statement as well so that it catches if a user trys to do something that
		will cause a stack overflow, underflow, or invalid calculator operators. The program will loop
		so that the user can continue to perfom calculations

	p: print top value of stack and allow user to continue calculations in new line
	n: prints top value of stack and removes it without printing a new line so calculations
		can be done with top value
	f: prints entire stack using a temporary stack and prints a new line
	c: pops all items out of the stack, resetting it to empty
	d: allows user to create a copy of the top item in the stack (useful for computing squares)
	r: switches top two values of stack
	+: program recognizes operater and pops top two values and adds them together, pushing the 
		final answer back onto the stack
	-: subtracts the top two values after popping them off the stack, and pushes final answer
		back onto the stack
	*: multiplies top two values and pushes back onto stack
	/: divides top two values and pushes result back onto stack
	%: finds the remainder of the division and pushes onto stack
