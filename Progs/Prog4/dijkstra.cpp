#include "queue.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.h"
#include <cstdlib>
#include <sstream>
#include <vector>
#include <climits>
#include <iomanip>
#include <stack>
#include <set>

using namespace std;

#include "SeparateChaining.h"


struct VertexType
{
	string name;
	bool marked;
	int distance;
	string previous;	
};

void insertionSort(string cities[], int numVertices);
void checkInFile(int argc);
void buildDGraph(Graph<string> &dGraph, string filename, string cities[], int &numVertices, int &numEdges, VertexType myVertices[]);
void printCities(Graph<string> dGraph, int numVertices, VertexType myVertices[], string cities[]);
string setStart(string start, int numVertices, VertexType myVertices[]);
void printRow(int location, VertexType myVertices[]);
int findMin(VertexType myVertices[], int numVertices);
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[]);
bool allMarked(int numVertices, VertexType myVertices[]);
void assignWeights(Graph<string> &dGraph, int numVertices, VertexType myVertices[], int startingLocation, Queue<string>& getTo);
void fileExist(const string filename);
bool checkForCity(string cities[], string city);
int findIndex(string startLoc, int numVertices, VertexType myVertices[]);
void printMatrix(Graph<string>& dGraph, int numVertices, VertexType myVertices[]);

int main(int argc, char* argv[])
{
	checkInFile(argc);	// Checks to see if Filename is given

	// Creation of Input File:

	//array starts at 0
	string filename = argv[1];
	//check if file exists
	fileExist(filename);
	
	Graph<string> dGraph; 
	int numVertices;
	int numEdges;
	VertexType myVertices [50];
	string cities [50];
	buildDGraph(dGraph, filename, cities, numVertices, numEdges, myVertices);	// Builds the Graph using the data from the external file.
	printCities(dGraph, numVertices, myVertices, cities);	// Prints Cities found in file
	dijkstra(dGraph, numVertices, myVertices);	// Computes Dijkstra's Algorithm:
}

// Checks to see if Filename is given:
	void checkInFile(int argc)
	{
		if(argc==1)
		{
			cout<< "ERROR! No file entered. Exiting."<< endl;
			exit(1);
		}
	}
//Checks to see if file exits
	void fileExist(const string filename)
	{
		ifstream ifile(filename.c_str());
		if((bool)ifile==false)
		{
			cout<< "File Does Not Exist. Exiting." << endl;
			exit(1);
		}			
	}

	// Computes Dijkstra's Algorithm:
	void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[])
	{
		//gets starting vertex
		string start;
		string startLoc= setStart(start, numVertices, myVertices);
		int startIndex=findIndex(startLoc, numVertices, myVertices);

	//	myVertices[startIndex].marked=true;
	//	myVertices[startIndex].distance=0;
	//	myVertices[startIndex].previous="N/A";

		Queue<string> getTo; 
	
		string currCity= myVertices[startIndex].name;
		dGraph.GetToVertices(currCity, getTo);	
		assignWeights(dGraph, numVertices, myVertices, startIndex, getTo);
		
								

				
	}

	//finds index of passed vertex
	int findIndex(string find, int numVertices, VertexType myVertices[])
	{
		for(int i=0; i<numVertices; i++)
		{
			if(myVertices[i].name == find)
			{
				return i;
			}
		}
	}

	// Assign weights based on the starting location
	void assignWeights(Graph<string> &dGraph, int numVertices, VertexType myVertices[], int startingLocation, Queue<string>& getTo)
	{
	
		myVertices[startingLocation].marked=true;
		myVertices[startingLocation].distance=0;
		myVertices[startingLocation].previous="N/A";
		printRow(startingLocation, myVertices);
		int index;

		while(!allMarked(numVertices, myVertices))
		{
			dGraph.GetToVertices(myVertices[startingLocation].name, getTo);
			while(!getTo.isEmpty())
			{
				string adjacent=getTo.getFront();
				index=findIndex(adjacent, numVertices, myVertices);
				int weight= dGraph.WeightIs(myVertices[startingLocation].name, adjacent);		

				if(!(myVertices[index].marked) && (myVertices[startingLocation].distance + weight) < myVertices[index].distance) 
				{ 
					myVertices[index].distance= myVertices[startingLocation].distance + weight;
					myVertices[index].previous = myVertices[startingLocation].name;
				}
				
				getTo.dequeue();				
			}
		//find next smallest vertice
		int minIndex=-1;		
		int min= INT_MAX;
		for(int i=0; i<numVertices; i++)
		{
			if(!myVertices[i].marked && min > myVertices[i].distance)
			{
				minIndex=i;
				min=myVertices[i].distance;
			}
		}
		
		startingLocation= minIndex;
		myVertices[startingLocation].marked=true;
		printRow(startingLocation, myVertices);
		
			
		}	
	}

	// Checks to see if all Vertices have been marked:
	bool allMarked(int numVertices, VertexType myVertices[])
	{
		for(int i=0; i<numVertices; i++)
		{
			if(myVertices[i].marked==false)
			{
				return false;
			}		
		}
		return true;
	}

	// Builds the Graph using the data from the External File:
	void buildDGraph(Graph<string> &dGraph, string filename, string cities[], int &numVertices, int &numEdges, VertexType myVertices[])
	{
		ifstream infile(filename.c_str());
		string originCity;
		int travel;
		getline(infile, originCity, ';');


		while(infile)	
		{
			
			string destCity;
			getline(infile, destCity, ';');

			infile >> travel;
			infile.ignore();

					
			//check if string origin/dest city already exists
			bool isCity = checkForCity(cities, originCity);
			if(isCity==false)
			{	
				VertexType firstVertex = {originCity, false, INT_MAX, "N/A"};
				myVertices[numVertices] = firstVertex;
				dGraph.AddVertex(originCity);
				cities[numVertices]=originCity;
				numVertices++;
			}
			isCity= checkForCity(cities, destCity);
			if(isCity==false)
			{
				VertexType secondVertex = {destCity, false, INT_MAX, "N/A"};
				myVertices[numVertices] = secondVertex;
				dGraph.AddVertex(destCity);
				cities[numVertices]=destCity;
				numVertices++;
			}

			dGraph.AddEdge(originCity, destCity, travel);
			getline(infile, originCity, ';');
		}
		insertionSort(cities, numVertices);
	}

	bool checkForCity(string cities[], string city)
	{
		for(int i=0; i<50; i++)
		{
			if(cities[i]==city)
			{
				return true;
			}
		}
		
		return false;
	}

	// Prints Cities found in External File:
	void printCities(Graph<string> dGraph, int numVertices, VertexType myVertices[], string cities[])
	{
		cout<< "^^^^^^^^^^^^^^^^^^^^ DIJKSTRA'S ALGORITHM ^^^^^^^^^^^^^^^^^^^^^^" << endl;
		cout<< endl;
		cout<< endl;
		cout<<'\t'  << "A Weighted Graph Has Been Built For These " << numVertices << " Cities" << endl;

		int index=0;
		int numRuns= (numVertices/3) + 1;
		for(int i=0; i<numRuns; i++)
		{
			int temp= numVertices-index;
			if(temp < 3)
			{
				for(int i=0; i<temp; i++)
				{
					cout << '\t' << '\t' << cities[index] << '\t' << '\t';
					index++;
				}
			}
			else
			{
				cout<< '\t' << '\t' << cities[index] << '\t' << '\t' << cities[index++] << '\t' << '\t' << cities[index++] << endl;	
				index++;
			}
		}
		cout<< endl;
	}

	// Sorts the Cities Alphabetically:
	void insertionSort(string cities[], int numVertices)
	{
		for(int i=0; i<numVertices; i++)
		{
			string temp = cities[i];
			int j;
			for(j=i; j>0 && temp < cities[j-1]; j--)
			{
				cities[j]= cities[j-1];
			}
		
			cities[j]=temp;
		}
	}

	//Sets the Starting Value in Dijsktra's Algorithm:
	string setStart(string start, int numVertices, VertexType myVertices[])
	{
		cout << " Please input your starting vertex: ";
		string response;
		getline(cin,response);
		bool isThere = false;
		for (int i = 0;	i < numVertices; i++)
		{
			if (myVertices[i].name.compare(response) == 0)
			{
				start = response;
				return start;
			}
		}
		while (!isThere)
		{
			cout << " Starting location does not exist..." << endl;
			cout << " Please input your new vertex: ";
	        	string response;
	        	cin >> response;
			for (int i = 0; i < numVertices; i++)
	        	{
	                	if (myVertices[i].name.compare(response) == 0)
				{
	                        	start = response;
	                        	return start;
	                	}
	        	}
		}
	}

	// Finds the minimum non-marked values in VertexType Array:
	int findMin(VertexType myVertices[], int numVertices)
	{
 		int minWeight = INT_MAX - 1;
                int minThing = -1;
		for (int i = 0; i < numVertices; i++)
                {
                        if (myVertices[i].distance < minWeight && !myVertices[i].marked)
                        {
                                minWeight = myVertices[i].distance;
                                minThing = i;
                        }
			else if (myVertices[i].distance == minWeight && !myVertices[i].marked)
        		{
                                minWeight = myVertices[i].distance;
                                minThing = i;
                        }

		}        
		return minThing;
	}
	
	// Prints a given row in a Summary Table:
	void printRow(int location, VertexType myVertices[])
	{
		if (myVertices[location].distance != -1)
		cout << setw(14) << myVertices[location].name << setw(18) << myVertices[location].distance << setw(16) << myVertices[location].previous << endl;
		else
		 cout << setw(14) << myVertices[location].name << setw(18) << "Not On Path" << setw(16) << myVertices[location].previous << endl;
	}

	//prints out adjancy matrix
	void printMatrix(Graph<string>& dGraph, int numVertices, VertexType myVertices[])
	{
		for(int i=0; i<numVertices; i++)
		{
			for(int j=0; i<numVertices; j++)
			{
				cout<< dGraph.WeightIs(myVertices[i].name, myVertices[j].name) << " ";
			}
		}
	}	

