using namespace std;
#include "huffman.h"
#include <iostream>
	int main()
	{
		HuffmanTree H;
		H.insert('a', 1);
		H.insert('b', 1);
		H.insert('c', 1);

		H.build();
		cout<<H.GetCode('a') << endl;	
	

		return 0;
	}
