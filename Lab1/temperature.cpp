#include <iostream>
using namespace std; 

double convert(double value);

	int main()
	{
		double tmp; 	
		cout << "Please enter a Celsius value: " ;
		cin >> tmp; 
		
		double farenheit=convert(tmp);
		cout << tmp << " degrees Celsius is " << farenheit << " degrees Fahrenheit. " << endl;  
		return 0;
	}

	double convert (double tmp)
	{	
		double farenheit;
		farenheit= (1.8 * tmp) + 32.0;
		return farenheit; 
	}		

	

