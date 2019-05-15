using namespace std;
#include "huffman.h"
#include <iostream>
#include <climits>

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

	void HuffmanTree:: insert(char ch, int weight)
	{	
    		HNode newNode = {ch, weight, 0, -1}; 
 		built = false;
    		nodes.push_back(newNode);
    		numChars++;
	}

	bool HuffmanTree:: inTree(char ch)
	{
		bool answer= false;
		for(int i=0; i<numChars; i++)
		{
			if(nodes[i].ch ==ch)
			{
				answer=true; 
			}
		
		}	
		return answer;
		
	}	

	int HuffmanTree:: GetFrequency(char ch) 
	{
		int location = lookUp(ch);
		GetFrequency(location);			
	}	

	int HuffmanTree:: GetFrequency(int i)
	{
		return nodes[i].weight;
	}

	int HuffmanTree:: lookUp(char ch) 
	{
		//will return -1 if character is not in tree
		int location = -1;
		if(inTree(ch))
		{
			for(int i=0; i<numChars; i++)
			{
				if(nodes[i].ch == ch)
				{
					location=i;
				}
			}
		}
		
		return location;
	}	

	string HuffmanTree:: GetCode(char ch) 
	{
		int loc=lookUp(ch);
		return GetCode(loc);
	}


	string HuffmanTree:: GetCode(int i) 
	{
		if(nodes[i].parent == 0)
			return "";
		else
			return(GetCode(nodes[i].parent) + (char)(nodes[i].childType + '0'));
	}

	void HuffmanTree:: PrintTable() 
	{
		cout<< '\t'  <<"## ENCODING TABLE FOR ZIP FILE ##" << endl;
		cout<< "Index" << '\t' << "Char" << '\t' << "Weight" << '\t' << "Parent" << '\t' << "ChildType" << endl;
		
		int counter=1;
		for(int i=0; i<numChars; i++)
		{
			if(nodes[i].ch == '\0')
			{
				cout<< i << '\t' << "T" << counter++ << '\t' << nodes[i].weight << '\t' << nodes[i].parent << '\t' << nodes[i].childType << endl;	
				
			}
			else if(nodes[i].ch == '\n')
			{
				cout<< i << '\t' << "nl"  << '\t' << nodes[i].weight << '\t' << nodes[i].parent << '\t' << nodes[i].childType << endl;	
			}
			else if(nodes[i].ch == ' ')
			{
				cout<< i << '\t' << "sp" << '\t' << nodes[i].weight << '\t' << nodes[i].parent << '\t' << nodes[i].childType << endl;
			}
			else	
				cout<< i << '\t' << nodes[i].ch << '\t' << nodes[i].weight << '\t' << nodes[i].parent << '\t' << nodes[i].childType << endl;	
		}
		 
	}

	int HuffmanTree:: numNodes() 
	{
		return numChars;
	}

	void HuffmanTree:: build()
	{
		int stop= (2*numChars)-1;
		int min1, min2;
		
		while(numChars < stop)
		{
			int currSmall;
			currSmall=INT_MAX;
		
			for(int i=0; i<numChars; i++)
			{
				if((nodes[i].parent==0) && (nodes[i].weight < currSmall))
				{
					min1=i;
					currSmall=nodes[i].weight;
				}
			}

			currSmall=INT_MAX;
		
			for(int y=0; y<numChars; y++)
			{
				if((nodes[y].parent==0) && (nodes[y].weight < currSmall)  && (y != min1) )
				{
		       			min2=y;
					currSmall=nodes[y].weight;
				}
			}
		
			HNode total = {'\0', (nodes[min1].weight + nodes[min2].weight), 0, -1};
			nodes.push_back(total);
	  		
			//sets parent
	  		nodes[min1].parent = numChars;
	  		nodes[min2].parent = numChars;
		
			
	  		//sets Left or Right child
	  		nodes[min1].childType = 0;
	  		nodes[min2].childType =1;
			
			numChars++;

			
		}
	
		built=true;
	}
 
	char HuffmanTree:: getChar(int index)
	{
		return nodes[index].ch;
	}
