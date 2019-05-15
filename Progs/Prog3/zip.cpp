using namespace std;
#include "huffman.h"
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>

	void OpenFile(ifstream& infile, int argc, char *argv[], char* filename);
	void compressFile(ofstream& outfile, int totalChar, HuffmanTree& H, char* filename, string& compress);
	void readFile(ifstream& infile, HuffmanTree& H, int Letters[], string& compress);
	void makeTree(HuffmanTree& H, int Letters[], int& totalChar);
//	const int NumLetters = 256;	

	int main(int argc, char *argv[])
	{
		HuffmanTree H;
		ifstream infile;
		ofstream outfile;
		int Letters[256];		
		int totalChar=0;
		char* filename= argv[argc-1];
		string compress= "";
		OpenFile(infile, argc, argv, filename);		
		readFile(infile, H, Letters, compress);
		makeTree(H, Letters, totalChar);
		compressFile(outfile, totalChar, H, filename, compress);
		return 0;
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
		exit(1);
	}

        string file = (string) filename;
         infile.open(file.c_str());
  }
  
  void compressFile(ofstream& outfile, int totalChar, HuffmanTree& H, char* filename, string& compress)
  {
	
	string line= "";
	line += filename;
        line+=".zip";
        outfile.open(line.c_str());
	
	outfile << totalChar << endl;
	char ch;

	for(char ch= char(1); ch<=char(126); ch++)
	{
		bool inTree = H.inTree(ch);
		if(inTree)
		{
			int ascii= (int) ch;
			outfile<< ascii << " "  << H.GetCode(ch) << endl;
		}
	}
	string end= "";
	for(int i=0; i<compress.length(); i++)
	{
		end+= H.GetCode(compress[i]);	
	}
	outfile<< end << endl;

	//print out compression ratio
	double Bits= (double) end.length();
	double chars= (double) totalChar*8.0;
	double ratio = (1-(Bits/chars)) * 100;
	cout << "File Successfully Compressed to " << end.length() << " Bits ("<< setprecision(4)  << fabs(ratio) << "%)" << endl;
  }

  void readFile(ifstream& infile, HuffmanTree& H, int Letters[], string& compress)
  {
	char ch;

	for(char ch= char(0); ch <= char(126); ch++)
	{
		Letters[ch]=0;
	}
	
	
	infile.get(ch);
	while(infile)
	{
		compress += ch;
		Letters[ch] += 1;
		infile.get(ch);
	}
		
  }

  void makeTree(HuffmanTree& H, int Letters[], int& totalChar)
  {	
	for(char ch= char(0); ch<= char(126); ch++)
	{
		if(Letters[ch] != 0)
		{
			totalChar++;
			H.insert(ch, Letters[ch]);		
				
		}
	}
	
	H.build();
  }
