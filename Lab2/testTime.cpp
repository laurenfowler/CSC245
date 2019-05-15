#include "time.h"
#include <iostream>
using namespace std;

	int main()
	{
		Time myTime(9,30, 0);
		myTime.Write();
		myTime.WriteAmPm();
		myTime.Set(8,0,0);
		myTime.Write();
		myTime.Mealtime();

		Time schedules[10];
		
		for (int i=0; i<10; i++)
		{
			schedules[i].Set(11,0,0);
			schedules[i].Write();
		}
		return 0;
	}


