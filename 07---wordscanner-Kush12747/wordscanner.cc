/**
*   Kush Gandhi
*   z1968933
*   CSCI-340 section Harper
*   10/24/22
*   Assignment 7
* 
*   I certify that this is my own work and where appropriate an extension
*   of the starter code provided for the assignment.
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <iterator>

using namespace std;

void print_words(const map<string, int>&m);
void get_words(map<string, int>& map);
void clean_entry(const string& original, string& clean);

int inputStreamCount = 0; //tracks input stream count, global variable

int main()
{
    //make a temp map
    pair<string, int> first;
    pair<string, int> second;
    map<string, int> words;
    
    //call functions to perform
    get_words(words);
    print_words(words);

    return 0;
}

/**
*   @brief: This function cleans the words from punctuation marks.
* 
*   @param const original: orginal word from inout stream
*   @param clean: containes the words after cleaning
*/
void clean_entry(const string& original, string& clean)
{
    //indicates the postion of the first alphanumeric
    auto first_it = find_if(original.begin(), original.end(), [](char unaryPred1)
    {
        return (isalnum(unaryPred1));
    });

    //inidicates the position after the last alphanumeric character
    auto second_it = find_if(clean.begin(), clean.end(), [](char unaryPred2)
    {
        return (isalnum(unaryPred2));
    });

   //string str(first_it, second_it);

    //convert all capital letters into lowercase letters
    for_each(clean.begin(), clean.end(), [](char checkLowercase)
    {
        return tolower(checkLowercase);
    });
}

/**
*   @brief: This function reads the words from the
*   input stream and removes any punctation marks.
* 
*   @param m: Reference the map to proces words
*/
void get_words(map<string, int>& m)
{
    string input;

    while (cin >> input) //loop to read words from file
    {
        clean_entry(input, input); //call the subrotuine of clean_entry()
	
	inputStreamCount++;

        //if 0 then the words conatines punctuation marks, so we ignore it
        if (input.length() == 0)
        {
            continue;
        }
        else
        {
            m[input]++; //this copies the string into map
        }
    }
}

/**
*   @brief: This function prints the list of words, frequences,
*   number of nonempty words, and number of distinct words
* 
*   @param m: Refernce for map
*/
void print_words(const map<string, int>& m)
{
    int NO_ITEMS = 4;
    int ITEM_WORD_WIDTH = 14;
    int ITEM_COUNT_WIDTH = 3;
    size_t mapSize = m.size(); //size of the map
    int newLineCount = 0;

    //iterator to print the words and count to the terminal
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout  << left << setw(ITEM_WORD_WIDTH) << (*it).first;
        cout << left << ":" << setw(ITEM_COUNT_WIDTH) << (*it).second;
        
        newLineCount++;

	//every 4 lines we make a new line
        if (newLineCount % NO_ITEMS == 0)
        {
            cout << "\n";
        }
    }

    //prints the total number of words in input and output stream
    cout << "\nnumber of words in input stream    :" << inputStreamCount << endl;
    cout << "number of words in output stream   :" << mapSize << endl;
}
