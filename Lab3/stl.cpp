#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>

using namespace std;
	
	void Initialize(vector <int> &v);
	void Print(vector <int> v);
	void Reverse(vector <int> &v);

	int main()
	{
		stack<string> s1, s2;
		s1.push("Hi there");
		s1.push("Bye");
		s2.push("Hi there");
		s2.push("Bye");

		if(s1==s2)
			cout<< "s1 == s2" << endl;
		else if(s1<s2)
			cout<< "s1 < s2" << endl;
		else if(s2<s1)
			cout<< "s2 < s1" << endl;

		vector <int> v;	
		Initialize(v);
		Print(v);
		Reverse(v);
		cout<< endl;
		Print(v);
		


	  return 0;
	}

	void Initialize(vector<int> &v)
	{
		int input;
		cout<< "please enter 5 integers" << endl;
		for(int i=0; i<5; i++)
		{
			cin>>input;
			v.push_back(input);
		}		
	}

	void Print(vector<int> v)
	{
		for(int i=0; i<v.size(); i++)
		{
			cout<<v[i]<<" ";
		}
	}

	void Reverse(vector<int> &v)
	{
		vector<int> temp;
		
		for(int i=0; i<v.size(); i++)
		{
			temp.push_back(v[i]);
				
		}

		for(int i=0; i<temp.size(); i++)
		{
			v[i]=(temp[temp.size()-i-1]);	
		}

	}





