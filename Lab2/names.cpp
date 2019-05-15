
#include <string>
#include <iostream>
using namespace std;

void BreakDown (string name, string& first, string& last, string& mi);
int main()
{
	string name, first, last, mi;

	cout << "Name? <Last, First MI.> ";
	getline (cin, name);
		
	BreakDown (name, first, mi, last);

	cout << "First Name Entered :  " << first << endl;
	cout << "Last Name Entered :  " << last << endl;
	cout << "Middle Initial Entered :  " << mi << endl;
	return 0;
}

void BreakDown (string name, string& first, string& mi, string& last)
{
	// pre  : name is initialized with a full name
	// post : first, mi, and last contain the individual components
        //        of that name

//.find in c++ to find we want the length where it ends as the second parameter 
//& locks in changes
//subract 5 because of space, middle inital, etc. 

	mi= name.substr((name.find('.')-1) , 1);  
	last= name.substr(0, name.find(','));
	first=name.substr((name.find(',')+2) , (name.find('.')-last.length()-4) );	


} 
