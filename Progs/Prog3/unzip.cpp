using namespace std;
#include "huffman.h"
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <map>

void OpenFile (ifstream& infile, int argc, char *argv[], char* filename);
void readFile(ifstream& infile, map <string, char>& M, int& numOfChars, string& totalCode);
void inflate(ofstream& outfile, map<string, char>& M, string& totalCode, char* filename);

	int main(int argc, char *argv[])
	{
		ifstream infile;
		ofstream outfile;
    
		map <string, char> M;	
		int numOfChars;
		string totalCode;
    char* filename= argv[argc-1];

		OpenFile(infile, argc, argv, filename);
		readFile(infile, M, numOfChars, totalCode);
		inflate(outfile, M, totalCode, filename);
	}

 void OpenFile (ifstream& infile, int argc, char *argv[], char* filename)
   {
        if (argc == 1)
        {
                cout << "Error!! No File Entered." << endl;
                exit(1);
        }	
	if(!filename)
	{
		cout<< "File does not exist." << endl;
	}	
	string file = (string) filename;
	if(file.substr(file.find('.'), 4) != ".zip")
	{
		cout<< "Not a .zip file" << endl;
		exit(1);
	}
	
        infile.open(file.c_str());
  }
  
  void readFile(ifstream& infile, map <string, char>& M, int& numOfChars, string& totalCode)
  {

	infile>> numOfChars;

   
	char ch;
	int temp;
	string code;

	for(int i=0; i<numOfChars; i++)
	{
		infile>>temp>>code;
		ch=(char) temp;
		M[code]=ch;
	}	
  	
	infile>> totalCode;
  }

 void inflate(ofstream& outfile, map<string, char>& M, string& totalCode,char* filename )
 {
    string line= "";
    line += filename;
    line.erase(line.find('.'),4);
    outfile.open(line.c_str());
	
	string checkChar;
	string reinflated;
	char temp;

	for(int i=0; i<totalCode.length(); i++)
	{
		checkChar+=totalCode[i];
		if(M.find(checkChar) != M.end())
		{
			temp=M[checkChar];
			reinflated+=temp;
			checkChar="";			
		}	
	}	

	outfile<< reinflated << endl;
	cout<< "File Successfully Inflated Back To Original" << endl;
	
 }
