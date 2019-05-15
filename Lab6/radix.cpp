#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

	int maxElemLength(const vector<int>& v);
	int GetDigit(int number, int k);
	vector<queue<int> > ItemsToQueues(const vector<int>& L, int k);
	vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals);
	void RadixSort(vector<int>& L, int numDigits);
	void PrintVector(const vector<int>& L);


	int main()
	{
		vector<int> L;
		int nums[]= {380,95,345,382,260,100,492};
		cout<< "Before radix sort: ";
		for(int i=0; i<7; i++)
		{
			L.push_back(nums[i]);
			cout<<nums[i]<< " ";
		}
		cout<< endl;
	
		int maxElem=maxElemLength(L);
		RadixSort(L, maxElem);

		cout<< "After radix sort :";
		PrintVector(L);
	return 0;
	}
	

	int maxElemLength(const vector<int>& v)
	{
		int max= v[0];
		for(int i=0; i<v.size(); i++)
		{
			if(max<v[i])
			{
				max=v[i];
			}
		}	
		
		if(max<10)
			return 1;
		if(max>=10 && max<100)
			return 2;
		if(max>=100)
			return 3;
	}	
	
	int GetDigit(int number, int k)
	{

		while(k>0)
		{
			number/=10;
			k--;	
		}
		return number%10;

	}
	
	vector<queue<int> > ItemsToQueues(const vector<int>& L, int k)
	{
		vector<queue<int> > QA(10);
		for(int i=0; i<L.size(); i++)
		{
			int numAtPlace= GetDigit(L[i], k);
			QA[numAtPlace].push(L[i]);
		}
		return QA;

	}
	
	vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals)
	{
		int pos=0;
		vector<int> v(numVals);
		for(int i=0; i<10; i++)
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
	
	void RadixSort(vector<int>& L, int numDigits)
	{
		vector<queue<int> > QA(10);
		for(int i=0; i<numDigits; i++)
		{
		
			QA=ItemsToQueues(L, i);
			L=QueuesToArray(QA, L.size()); 
		}
	}
	
	void PrintVector(const vector<int>& L)
	{
		for(int i=0; i<L.size(); i++)
		{
			cout<<L[i]<< " "; 
		}
		cout<< endl;
	}
