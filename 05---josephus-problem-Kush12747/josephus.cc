/**
*   Kush Gandhi
*   z1968933
*   CSCI 340-PE1 section harper
*   10/10/22
* 
*   I certify that this is my own work and where appropiate an extension
*   of the starter code provided for the assignment
*/

#include "josephus.h"

#include <list>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <getopt.h>
using namespace std;

void print_underlined_string(const string& message);
void print_list(const list<string>& collection, const unsigned& eliminations, int num_cols);


/**
* Print a 'Usage' message and exit(1).
*
* @param a0 The name of the command to include in the usage message.
*****************************************************************************/
static void usage(const char* a0)
{
    std::cerr << "Usage: " << a0 << " [-n number of people] [-m modulus] [-p print frequency] [-c print columns]" << std::endl;
    exit(1);
}


/**
* Create a std::list of prople with generated ID/names and reduce the
* list as per the Josephus problem algorithm.
*****************************************************************************/
int main(int argc, char** argv)
{
    unsigned num_people = 41;       // The number of people to start with
    unsigned modulus = 3;           // The count used to determine the elimination
    unsigned print_frequency = 13;  // How often to print the state of the system
    unsigned num_cols = 12;         // Number of colums to print per line

    int opt;
    while ((opt = getopt(argc, argv, "n:m:p:c:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            std::istringstream(optarg) >> num_people;
            break;
        case 'm':
            std::istringstream(optarg) >> modulus;
            break;
        case 'p':
            std::istringstream(optarg) >> print_frequency;
            break;
        case 'c':
            std::istringstream(optarg) >> num_cols;
            break;
        default:
            usage(argv[0]);
        }
    }

    if (optind < argc)
        usage(argv[0]); // If we get here, there was extra junk on command line

    list<string> people; //created a list to populate
    unsigned int count = 0; //counts the number of eliminations

    //this genereates the list by populating it from the SEQ class
    generate_n(back_inserter(people), num_people, SEQ(num_people));
    print_list(people, count, num_cols); //print the intial list

    while(people.size() > 1) 
    {
        for (list<string>::iterator it = people.begin(); it != people.end();)
        {
	    it = people.erase(it);
	    ++it;
	    count++;

	    if (count == print_frequency)
	    {
                print_list(people, count, num_cols);
	    }

	    //when 1 person is remaining then print final list
	    if (people.size() == 1)
	    {
	        print_underlined_string("");
	        print_list(people, count, num_cols);
	    }
        }
    }
   return 0;
}

/**
 *    @brief: This function here prints the list of people in the list and also prints 
 *    the ones who are elminated.
 *
 *    @param collection: reference for list of people
 *    @param eliminations: number of eliminations in the list
 *    @param num_cols: number of colmunsto display list output
 */
void print_list(const list<string> &collection, const unsigned& eliminations, int num_cols)
{
    //prints out the intial group or triggers else block to print
    //list heading for number of elminations
    if (eliminations == 0)
    {
        cout << "Initial group of people" << endl;
        cout << "-----------------------" << endl;
    }
    else
    {
        cout << "After eliminating " << eliminations << " people" << endl;
        cout << "---------------------------" << endl;
    }

    int newLineCount = 0;//tracks the number of numbers in a line

    //used a iterrator to print the list contents
    for (auto it = collection.begin(); it != collection.end(); ++it)
    {
	cout << " " << *it << ",";
	newLineCount++;
	if (newLineCount % num_cols == 0)
	{
	    cout << endl;
	}
    }
    cout << endl << endl; //line break format

}

/**
 *  @brief: This function here prints the underline from the text in print_list()
 *
 *  @param message: prints the underline  heading of the list
 */
void print_underlined_string(const string &message)
{
    cout << "Eliminations Completed" << endl;
}
