1. The client program allows a user to edit a basic text file by using commands such at Insert (I), Delete (D), Previous Line (P)
	Next Line (N), Print (P), and Exit (E)
2. Input was taken in to the client program through the command line and inserts each line into a doubly linked list. Any changes 
	made to the file were saved out to the testfile 
3. 
	- In the implementation file, there are 10 methods that can be used by the client file. These methods are:
		i.    goToTop(): moves currLine pointer up to the top of the linked list
		ii.   goToBottom(): moves currLine pointer to bottom of the linked list
		iii.  insertLine(string newLine): inserts a line given by the user into the line below the currLine pointer
		iv.   deleteLine(): deletes the line pointed to by the currLine pointer
		v.    printList(): prints out the entire linked list
		vi.   getCurrLine(): returns information that the currLine pointer is pointing to
		vii.  moveNextLine(): takes user to line below the current line and resets current line pointer
		viii. movePreviousLine(): takes user to line above current line and resets current line pointer
		ix.   getCurrLineNum(): returns the number of the line pointed to by current line pointer
		x.    getLength(): returns length of the linked list

	-The main method creates a new linked list, and populates it using a method that reads in a file inputted through the 
		keyboard. Once the file is read in, the list is printed out to the console. The user is then able to input an 
		option, read in as a character, to select a command option. The character enters a switch statement, that has a 
		case for each command. The switch statement is inside a do while loop, so that the program continues to run until
		the user inputs the character 'E', which breaks the loop. After this, there is a method that takes in any changes
		made to the file and sends it to the inputted file, effectivly saving any changes made by the user. 
	-Inside the client file there are 4 methods
		i.    openFile makes sure there is a file inputted through the command line 
		ii.   makeList populates the linked list
		iii.  insertLine reads in the line the user wants to input into the list
		iv.   PrintFile saves the changes out to the inputted file
	-The algorithm was placed inside a do while loop so that the program loops efficently and implemenation methods from 
		the LineList file were used to make code more efficent. 		
