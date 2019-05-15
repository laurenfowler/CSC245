#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

	struct RecType
	{
		int age;
		float weight;
		char gender;
	};

	int main()
	{
		int num=5;
		int *intPtr=NULL;
//		intPtr= &num;
		
		*intPtr= *intPtr*10;
		cout << "intPtr points to: " << *intPtr << endl;

		RecType *recPtr = new RecType;
		recPtr -> age = 25;
		recPtr -> weight = 190;
		recPtr -> gender = 'M';	
		recPtr -> age = recPtr -> age + 5;
	
		cout << "Three Fields pointed to by recPtr: "  <<  (*recPtr).age << " " << (*recPtr).weight << " " << (*recPtr).gender << endl;
		delete recPtr;	
		recPtr=NULL;

		char *strPtr= new char[50];
		strcpy (strPtr, "Operating Systems");
		cout << "strPtr points to: " << strPtr << endl;
//		cout << strlen(strPtr)  << endl;		

		int lowerCount=0;
		for(int i=0; i<strlen(strPtr);  i++)
			if(islower(strPtr[i]))
			{
				lowerCount++;
			}

		cout << "LowerCase Letters Pointed to by strPtr: " <<  lowerCount << endl;
		
		strPtr= (strPtr + 10);
		cout << "Printing strPtr after adding 10 : " <<  strPtr << endl;
		
		strPtr = (strPtr - 10);
		delete strPtr;
	
		return 0;
	}
