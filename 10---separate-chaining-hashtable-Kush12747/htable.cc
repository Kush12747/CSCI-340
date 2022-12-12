/**
*   Kush Gandhi
*   z1968933
*   CSCI-340 section harper
*   Assignment 10
*   11/21/22
* 
*   I certify that this is my own work and where appropiate an 
    extension of the starter code provided for the assignment.
*/
#include <iostream>
#include <iterator>

#include "htable.h"

using namespace std;

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string& s) {
    int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

    return n % hsize;
}

// You will complete the code below ...

/**
*   @brief: This is the constructor of the hash table where it resizes
*   both vectors by hs.
* 
*   @param hs: fixed size of the table
*/
HT::HT(const unsigned& hs) 
{
    hTable.resize(hs);
    pTable.resize(hs);
    hsize = hs;
}

/**
*   @brief: This is the destuctor which will be empty
*/
HT::~HT() {}

/**
*   @brief: This function inserts a item e into the hash table and checks if the 
*   key exists or not.
* 
*   @param e: item in hash table
*/
void HT::insert(const Entry& e) 
{
    int i = hash(e.key);

    list<Entry>& l = hTable[i]; //list container
    
    string match;

    //checks if the element is in the hash table then prints error message
    auto it = find_if(l.begin(), l.end(), [match](const Entry& e)
    {
        return match == e.key;
    });
    
    if (it != l.cend())
    {
        cout << "not inserted - duplicate key!!!";
    }
    else
    {
	//if not then we will make an insertion in front of the list container
        l.push_front(e);

        cout << " entry = " << i << endl;
    }
}

/**
*   @brief: This function searches for a record with the key.
* 
*   @param key: string key to be searched in the hash table
*/
void HT::search(const string& s) 
{
    int width = 6; //formatting table

    int i = hash(s);

    list<Entry>& l = hTable[i];

    //searches through the list to find the matched record in the hash table
    auto it = find_if(l.begin(), l.end(), [s](Entry e) 
    {
        return s == e.key;
    });

    //if it does then print the statment indiicating in the table else print a error message
    if (it != l.cend())
    {
        cout << " ==> number:" << setw(width) <<  it->num << " - item:" << it->desc << endl;
    }
    else
    {
	cout << " not in table!!" << endl;
        //cout << "key " << it->key << " not in table!!" << endl;
    }
}

/*
*   @breif: This function prints the subscripts of the hash table with the 
*   active records only.
*/
void HT::hTable_print() 
{
    //formating
    int width = 4;
    cout << endl;
    
    //loop through table dimensions
    for (int i = 0; i < hsize; i++)
    {
        list<Entry>& l = hTable[i]; //list container

	//loop through the conatiner to pring out records and keys
        for (auto it = l.begin(); it != l.end(); it++)
        {
            cout << i << setw(width) << " :" << it->key << setw(width) << "  - " << it->num << setw(width) << "  -  " << it->desc << endl;
        }
    }
}

/*
bool cmp(Entry *p, Entry *q)
{
   return p->key < q->key ? true : false;
}*/

/**
*   @brief: This function prints the contents of all of the active records
*   in the pTable.
*
*   error: Getting a segmentation fault.
*/
void HT::pTable_print() 
{
    int width = 4;
    vector<Entry>::const_iterator it;

   /* sort(pTable.begin(), pTable.end(), [](Entry *p, Entry *q)
    {
        return p->key < q->key ? true : false;
    });
  
    for (it = pTable.begin(); it != pTable.end(); it++)
    {
        cout << (*it)->key << setw(width) << " - " << (*it)->num << setw(width) << " - " << (*it)->desc << endl;
    }*/
}
