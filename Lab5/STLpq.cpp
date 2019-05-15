#include <queue>
#include <string>
#include <iostream>

using namespace std;

 void insertNames(priority_queue <string>& pq);
 void printNames(priority_queue <string> pq);

 int main()
 {
	priority_queue <string> pq;
	insertNames(pq);
	printNames(pq);		
  return 0;
 }

 void insertNames(priority_queue <string>& pq)
 {
	string array [] = { "Lauren", "John", "Howie", "Sarian", "Sahid", "Arjit", "David", "Mary", "Kevin", "Jesse" };
	
	int i=0;
	while(i < 10)
	{
		pq.push(array[i]);
		i++;
	}
 }

 void printNames(priority_queue <string> pq)
 {
	priority_queue <string> tempQ;
	while(!pq.empty())
	{
		cout<< pq.top() << " ";
		tempQ.push(pq.top());
		pq.pop();
	}
	cout<< endl;

 }
