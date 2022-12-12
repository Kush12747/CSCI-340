/**
*   Kush Gandhi
*   z1968933
*   CSCI-340 section harper
*   Assignment 11
*   12/5/22
* 
*   I certify that this is my own work and where appropiate an 
*   extension of the starter code provided for the assignment.
*/

#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#include "graph.h"

//global variable
//vector<bool> visit;
vector<int> collect;
int size;

/**
*   @brief: This function performs a depth first search which starts at v.
* 
*   @param v: vertex with the index value
*/
void Graph::Depthfirst(int v)
{
    bool *visit; //pointer to keep track of visit vertices

    visit = new bool[Getsize()];
    
    visit[v] = false;

    if (!visit[v])
    {
	collect.push_back(v);
    }
    //loop checks if vertex is not visit then do a depth first traversal recursively
    for (auto it = adj_list[v].begin(); it != adj_list[v].end(); it++)
    {
        if (!visit[*it])
        {
            collect.push_back(v);
	    Depthfirst(*it);
	}
        //delete []visit;
    }
}

/**
*   @brief: This function is the constructor which opens the file to
*   read in data and builds a adjacency list.
* 
*   @param filename: file contains information
*/
Graph::Graph(const char* filename)
{
    int nums;
    char characters;
    list<int> edgeList;

    //gets file and opens it
    ifstream file;
    file.open(filename);

    //error checks if file is vaild
    if (file.fail())
    {
	cout << "Error: can't open file";
	exit(-1);
    }

    while (!file.fail())
    {
        file >> size; //number of vertices

        //loop to get chars and insert them into vector labels
        for (int i = 0; i < size; i++)
        {
            file >> characters;
            labels.push_back(characters);
	}

	//loop to get the edges in the file 
	for (int i = 0; i < size; i++)
	{
	    //ignore the letters and lines
	    file.ignore();
	    file.ignore();

	    for (int j = 0; j < size; j++)
	    {
		file >> nums;
	        
		//checks if the number is a 1
		if (nums == 1)
	        {
		    //pushes it to a list to coleect the data
		    edgeList.push_back(j);
	        }
		else
		{
		    //ignore the 0
		    file.ignore();
		}
	    }
	    //then finally push the edgeList into the adj_list
	    adj_list.push_back(edgeList);
        }
    }
    //closes the file
    file.close();
}
/**
*   This is the destructor.
*/
Graph::~Graph(){}

/**
*   @brief: This function gets the size of graph.
*/
int Graph::Getsize() const
{
    int Size = size;
    return Size;
}

/**
*   @brief: This function traverse the graph and prints list of vertices
*   and edges.
*/
void Graph::Traverse()
{
    //Depthfirst();

    cout << "------- traverse of graph ------" << endl;

    //prints the traversal letters
    for (int i = 0; i < Getsize(); i++)
    {
	cout << labels[i] << " ";
    }
    cout << endl;

    for (auto it = collect.begin(); it != collect.end(); it++)
    {
	cout << "(" << labels[*it] << ", " << ") ";
    }	

    cout << "--------- end of traverse -------" << endl;
}

/**
*   @brief: This function prints the adjacency list for the graph.
*/
void Graph::Print() const
{
    //prints the heading output
    cout << "Number of vertices in the graph: " << size << endl << endl;
    cout << "-------- graph -------" << endl;

    //loop to get the labels which are A, B, C, D...
    for (int i = 0; i < Getsize(); i++)
    {
        cout << labels[i] << ": ";

	//This prints out the adjacency list for the graph
        for (auto it = adj_list[i].begin(); it != adj_list[i].end(); it++)
        {
            cout << labels[*it] << ", ";
        }
        cout << endl;
    }
    cout << "------- end of graph ------" << endl << endl;
}
