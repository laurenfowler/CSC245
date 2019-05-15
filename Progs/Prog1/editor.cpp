#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include "linelist.h"
using namespace std;

void PrintFile(ofstream& outfile, LineList& L, char *argv[]);
void OpenFile (ifstream& infile, int argc, char *argv[]);
void makeList(ifstream& infile, LineList& L);
void insert(LineList& L);

int main(int argc, char *argv[])
{
        LineList L;
        ifstream infile;	
	ofstream outfile;
        OpenFile(infile, argc, argv);
	makeList(infile, L);
	L.printList();

	
	char option;		
	do
	{	
	//	int currentLine = L.getCurrLineNum();
		cout << ">" << L.getCurrLineNum();
		cin>> option;

		switch(option)
		{
			case 'I':
				insert(L);
		//		currentLine = L.getCurrLineNum();
				break;
			case 'D':
				//seg fault, three pointers work when there is some space, need special case
				L.deleteLine();	
				break;
			case 'L':
				//fixed
				L.printList();
				break;
			case 'P':
				//fixed 
				L.movePrevLine();
				break;
			case 'N':
				//fixed
				L.moveNextLine();
				break; 
		}
	//	currentLine = L.getCurrLineNum();
//		cout << ">" << L.getCurrLineNum()
//		cin >> option;	
	} while(option != 'E');
	
	PrintFile(outfile, L, argv); 
	//method saves out to file 
       
	
	 return 0;
}

void OpenFile (ifstream& infile, int argc, char *argv[])
{
        if (argc == 1)
        {
                cout << "Error!! No File Entered." << endl;
                exit(1);
        }

        string filename = argv[1];
        infile.open(filename.c_str());
}

//populates linked list
void makeList(ifstream& infile, LineList& L)
{
	string s;
	while(getline(infile, s))
	{
		L.insertLine(s);
	}
	
}

//inserts line below current line
void insert(LineList& L)
{
	string s;
	getline(cin, s);
	L.insertLine(s);		
}

void PrintFile(ofstream& outfile, LineList& L, char *argv[])
{
        string filename = argv[1];
        outfile.open(filename.c_str());
	L.goToTop();

	for(int i=0; i<L.getLength(); i++)
	{
		outfile << L.getCurrLine() << endl;
		L.moveNextLine();
	}
}


