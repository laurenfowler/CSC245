#include <iostream>
#include "linelist.h"

using namespace std;

LineList::LineList()
{
	LineNode *line = new LineNode;
	LineNode *line2 = new LineNode;

	line -> info = topMessage;
	currLine = line;
	currLineNum = 1;
	length = 0;
	line2 -> info = bottomMessage;
	currLine -> back = NULL;
	currLine -> next = line2;
	line2 -> back = line;
	line2 -> next = NULL;
	currLineNum=0;	
}

void LineList::goToTop() 
{
	// Post : Advances currLine to line 1
        while(currLine->info != topMessage)
   	{
		currLine =currLine -> back;
//		currLineNum--;
  	}
//	currLineNum=0;
	currLine = currLine -> next;
	currLineNum=1;	

}

void LineList::goToBottom() 
{
	// Post : Advances currLine to last line
	while(currLine -> info != bottomMessage)
		currLine -> next;

	currLine = currLine -> back;
	currLineNum--; 

		
}

void LineList::insertLine(string newLine)
{
	// post : newLine has been inserted after the current line	
	
	
	//checks to make sure you are not inserting after bottom line
	if(currLine -> info == bottomMessage)
	{
		currLine= currLine -> back;
	}	
	
	LineNode *newNode = new LineNode;
	newNode -> info = newLine;
	newNode -> next = currLine -> next;
	newNode -> back = currLine;
	currLine -> next -> back = newNode;
	currLine -> next = newNode;
	currLine = newNode;
	length++;
	currLineNum++;
}

void LineList::deleteLine()
{
	// post : deletes the current line leaving currentLine
	//	  pointing to line following
	if(currLine -> info == topMessage || currLine -> info == bottomMessage)
	{
		return;
	}	
	else	
	{
		LineNode *line = new LineNode;
		LineNode *line1 = new LineNode;
		LineNode *tmpPtr= new LineNode;
		line = currLine -> back;
		line1 = currLine -> next;
		tmpPtr = currLine;

		line -> next = line1;
		line1 -> back = line;
		currLine = line;

		delete tmpPtr;
		
		length--;
		currLineNum--;
	}

}

void LineList::printList() 
{
	LineNode *mark = currLine;
 	int markNum = currLineNum;
	goToTop();
  	while(currLine-> info != bottomMessage)
	{
		cout << ">"  << currLineNum;
 		cout << " " << currLine -> info << endl;  	
		currLine = currLine -> next; 
		currLineNum++;
	}

	currLine = mark;
	currLineNum= markNum;
   
}

string LineList::getCurrLine() const
{	
	return currLine -> info;

}

void LineList::moveNextLine()
{
	// Post : Advances currLine (unless already at last line)
	if(currLine -> info != bottomMessage)
	{
		currLine = currLine -> next;
		currLineNum++;
	}	
}

void LineList::movePrevLine()
{
	// Post : Advances currLine (unless already at last line)
	if( currLine -> info != topMessage)
	{
		currLine = currLine -> back;
		currLineNum--;
	}	
	
}
int LineList::getCurrLineNum() const
{ 
	return currLineNum;
}

int LineList::getLength() const
{
	return length;
}
