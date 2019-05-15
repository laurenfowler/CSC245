#include <iostream>
using namespace std;

	bool testEqual(double *ptr1, double *ptr2);
	bool testAddress(double *ptr1, double *ptr2);
	int main()
	{
		double num1=1.0;
		double num2=1.0;
		
		double *ptr1 = &num1; 
		double *ptr2 = ptr1;
	
		bool answer=false;
		answer = testEqual(ptr1, ptr2);
		if (answer==true)
		{
			cout<< "Pointers are identical" <<endl;
		}
		else
			cout<< "Pointers are not identical" << endl;

		answer==testAddress(ptr1, ptr2);
		if(answer==true)
		{
			cout<< "Pointers have the same address" << endl;
		}
		else
			cout << "Pointers do not have the same address" << endl;
		

		

	return 0;
	}

	bool testEqual(double *ptr1, double *ptr2)
	{
		bool answer=false;
	
		if(*ptr1==*ptr2)
		{
			answer=true;
		}

		return answer;
	}

	bool testAddress(double *ptr1, double *ptr2)
	{
		bool answer=false;

		if(ptr1==ptr2)
		{
			answer=true;
		}
	
		return answer;
	}
