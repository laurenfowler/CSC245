#include <string>
#include "stack.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <locale>
#include "dsexceptions.h"


  using namespace std;
  void calculate(Stack <int> &dc, char operator1);
  void charFunction(Stack <int> &dc, char option);
  void readIn(Stack<int> &dc, string input);
 
  int main()
  {
	Stack<int> dc;
	string input;
	
	do
	{
		try
		{
			cin >> input;
			readIn(dc ,input);
		}
		catch(DataError exc)
		{
			cout << "You have entered in invalid experssion! Please re-enter\n";	
		}
		catch(DivisionByZero exc)
		{
			cout<< "Division by zero no allowed -- Re-enter input.\n";
		}
		catch(Underflow exc)
		{
			cout<< " Illegal pop -- The stack is empty" << endl;
		}
		catch(Overflow exc)
		{
			cout<< "Illegal push -- Stack is full" << endl; 
		}

	} while(cin); //loops while there is still input
	
  }

  void calculate(Stack <int> &dc, char operator1)
  {
	//precondition: takes parameters of stack and a char that designates operation to be performed
	//postcondition: performs designated operation and pushes answer back onto stack
	
	char operators [5]= {'+', '-', '*', '/', '%'};	
	bool isOperator=false;
	//checks to see if operator is a valid operator, else throws exception
	for(int i=0; i<5; i++)
	{
		if(operator1==operators[i])
		{
			isOperator=true;
		}			
	}
	if(isOperator==false)
	{
		throw DataError();
	}
	
	//takes top two items off stack and performs operation
	int x = dc.top();
	dc.pop();
	int y = dc.top();
	dc.pop();


	int answer;
	
	switch(operator1)
	{
		case '+':
			answer = x + y;
			dc.push(answer);
			break;
		case '-':
			answer= y - x;
			dc.push(answer);
			break;
		case '*':
			answer = y*x;
			dc.push(answer);
			break;
		case '/':
			if(x == 0)
			{
				throw DivisionByZero();
			}
			else
				answer = y/x;
				dc.push(answer);
			break;
		case '%':
			answer = y%x;
			dc.push(answer);
			break; 		
	}
 }


 void charFunction(Stack <int> &dc, char option)
 {
	//preconditon: takes paramters of stack and char option, enters switch statement  
	//postcondition: performs operation designated by user and prints out stack values when needed
	
	//temp stack holds values when printing dc stack
	Stack<int> temp;

	//used for switching top two values of stack
	int x;
	int y;
	

	switch(option)
	{
		case 'p':
			cout<< dc.top() << endl;
			break;
		case 'n':
			cout<< dc.topAndPop();
			break;
		case 'f':
			while(!dc.isEmpty())
			{
				cout<< dc.top()<< endl;
				temp.push(dc.topAndPop());
			}
			while(!temp.isEmpty())
			{
				dc.push(temp.topAndPop());
			}
			break;
		case 'c':
			while(!dc.isEmpty())
			{
				dc.pop();
			}
			break;
		case 'd':
			dc.push(dc.top());
			break;
		case'r':
			x=dc.top();
			dc.pop();
			y= dc.top();
			dc.pop();
			dc.push(x);
			dc.push(y);
			break;
		default:
			throw DataError();		
			
				
	
	}

 }

 void readIn(Stack <int> &dc, string input)
 {
	//preconditon: takes input from the user, parses the string, and seperates it into different values
	//postconditon: sends appropriate values to the right method

	string num;
	bool negative = false;
	int isChar;
	int number;

		for(int i=0; i<input.length(); i++)
		{
			int x=i;
			//isalpha checks to see if input is a character
			isChar=isalpha(input[i]);
			//does nothing if input[i] is a blank space
			if(input[i] == ' ')
			{

			}
			//checks for negative value indication
			if(isdigit(input[i]) || input[i] == '_')
			{
				if(input[i] == '_')
				{
					negative=true;
					x=x+1;	
				}
				if(input[i] == '_' &&  !isdigit(input[i+1]))
				{
					throw DataError();
				}
				//appends numbers to string while next char is still an int
				while(isdigit(input[x]))
				{	
					num+=input[x];
					x++;		
				}	
					
			   number = atoi(num.c_str());
			   if(negative)
			   {
				number= -1 * number;				
			   }

			   dc.push(number);
			   i=x-1;
			   //resets number
			   num.clear();
			}
			//sends to charFunction if item at input[i] is a char
			else if(isChar != 0)
			{
				charFunction(dc, input[i]);
			}
			else
			{
				calculate(dc, input[i]);	
			}	
					
 		}
 }	

