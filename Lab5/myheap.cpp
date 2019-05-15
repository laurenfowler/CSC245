#include <cmath>
#include "BinaryHeap.h"
#include <iostream>
#include "dsexceptions.h" 
using namespace std;

  void printHeap(const BinaryHeap<char> &B);
  int main()
  {
	BinaryHeap<char> PQ (50);
	
	//populate Heap
	for(int i=65; i<75; i++)
	{
		char toInsert= (char) i;
		PQ.insert(toInsert);
	}

	PQ.printLeaves();
	
/*
	PQ.deleteMin();
	
	cout << "Printing Left Subtree of the Root of Heap : ";
	PQ.printLtSubtree();
	cout << endl;

	cout<< "The Height of Heap is : ";
	int height = PQ.Height();
	cout << height << endl;

	cout << "The Maximum Value of Heap is : ";
	char max=PQ.findMax();
	cout << max << endl;

*/
	return 0;
  }

  void printHeap( const BinaryHeap<char>& B)
  {
	BinaryHeap<char> localB = B;
	
	while(! localB.isEmpty())
	{
		cout<< localB.findMin() << endl;
		localB.deleteMin();
	}
  }



