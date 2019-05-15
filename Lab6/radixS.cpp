#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

	int maxElemLength(const vector<string>& v);
	char GetChar(string word, int position);
	vector<queue<string> > ItemsToQueues(const vector<string>& L, char letter);
	vector<string> QueuesToArray(vector<queue<string> >& QA, int numLetters);
	void RadixSort(vector<string>& L, int numChars);
	void PrintVector(const vector<string>& L);
	void padString(vector<string>& v, int maxLength);
	void unPadString(vector<string>&v, int maxLength);

	int main()
	{
		vector<string> L;
		string a[]= {"zebra", "apple", "orange", "can", "candy", "a", "top", "pumpkin", "today", "parade"};
		cout<< "Before radix sort: ";
		for(int i=0; i<10; i++)
		{
			L.push_back(a[i]);
			cout<<a[i]<< " ";
		}
		cout<< endl;

		int numChars=maxElemLength(L);
		
		padString(L,numChars);	
		RadixSort(L, numChars);
		unPadString(L, numChars);

		cout<< "After radix sort :";
		PrintVector(L);
		return 0;
	}

	int maxElemLength(const vector<string>& v)
	{
		int max= v[0].length();
		for(int i=0; i<v.size(); i++)
		{
			if(max<v[i].length())
			{
				max=v[i].length();
			}
		}	
		return max;
		
	}	
	
	void padString(vector<string>& v, int maxLength)
	{
		for(int i=0; i<v.size(); i++)
		{
			if(v[i].length()<maxLength)
			{
				int numPad=maxLength-v[i].length();
				for (int j=0; j<numPad; j++)
				{
					v[i]=v[i]+ " ";
				}
			}
		}	
	}
//use substring, start at 0, find first instance of " "
	void unPadString(vector<string>&v, int maxLength)
	{
		for(int i=0; i<v.size(); i++)
		{
			string temp=v[i].substr(0, v[i].find(" "));
			v[i]=temp;
		}
	}
	

	
	
	char GetChar(string word, int position)
	{
		char Char=word[position];
		return Char;
	
	}
	
	vector<queue<string> > ItemsToQueues(const vector<string>& L, int k)
	{
		vector<queue<string> > QA(128);
		for(int i=0; i<L.size(); i++)
		{
			char charAtPlace= GetChar(L[i], k);
      			int place=(int) charAtPlace;
			QA[place].push(L[i]);
		}
		return QA;

	}
	
	vector<string> QueuesToArray(vector<queue<string> >& QA, int numLetters)
	{
		int pos=0;
		vector<string> v(numLetters);
		for(int i=0; i<128; i++)
		{
			while(!QA[i].empty())
			{
				v[pos]=QA[i].front();
				QA[i].pop(); 
				pos++;				
			}
		}
		return v;
	}
	
	void RadixSort(vector<string>& L, int numChars)
	{
		vector<queue<string> > QA(128);
		for(int i=numChars; i>=0; i--)
		{
			QA=ItemsToQueues(L, i);
			L=QueuesToArray(QA, L.size()); 
		}
	}


	void PrintVector(const vector<string>& L)
	{
		for(int i=0; i<L.size(); i++)
		{
			cout<<L[i]<< " "; 
		}
		cout<< endl;
	}
