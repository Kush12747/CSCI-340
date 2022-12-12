/*
*   Kush Gandhi
*   z1968933
*   CSCI 340-PE1 section harper
*   Assignment 3
*   Due Date: 9/19/22
*
*   I certify that this is my own work and where approiate an extension
*   of the starter code provided for the assignment.
*/

#include "twosearch.h"

#include <getopt.h>

#include <vector>
#include <iterator>
#include <random>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


/**
* see:
* https://en.wikipedia.org/wiki/Usage_message
* https://www.ibm.com/docs/en/aix/7.2?topic=commands-usage-statements
*
* @param a0 The value of argv[0] (the name of the command) so that it
*   can be printed.
*
* @note This function will terminate the application via exit(1).
******************************************************************************/
static void usage(const char* a0)
{
    std::cerr << "Usage: " << a0 << " [-l rand_low] [-h rand_high] [-a a_size] [-b b_size] [-x a_seed] [-y b_seed] [-c print_cols] [-w col_width]" << std::endl;
    std::cerr << "    rand_low   = rand() low bound (default=1)" << std::endl;
    std::cerr << "    rand_high  = rand() high bound (default=1000)" << std::endl;
    std::cerr << "    a_size     = size of vector A (default=200)" << std::endl;
    std::cerr << "    b_size     = size of vector B (default=100)" << std::endl;
    std::cerr << "    a_seed     = random seed for vector A (default=1)" << std::endl;
    std::cerr << "    b_seed     = random seed for vector B (default=3)" << std::endl;
    std::cerr << "    print_cols = number of colums per line (default=16)" << std::endl;
    std::cerr << "    col_width  = printed column value width (default=4)" << std::endl;
    exit(1);
} // End of usage()

/*
*   @brief: We are assigning random values to put in the vector vec which is
*   the vector that containes elements. We genrete the random numbers by
*   using the seed value and then initialize it with srand(seed) to generate number
*   between lo and hi by rand() % (hi - lo + 1) + lo.
*
*   @param vec: Refrence for vector
*   @param seed: value used to generate random numbers
*   @param lo: Starting number for random number generator
*   @param hi: Highest value we assign to the random number generator
*/
void init_vector(std::vector<int>& vec, int seed, int lo, int hi)
{
    srand(seed); // initialize the random number generator
    for (unsigned int i = 0; i < vec.size(); i++) // loop through vector to establish values of the vector
    {
        vec[i] = (rand() % (hi - lo + 1) + lo); // generate the random numbers and fill the vector
    }
}

/**
*   @brief: This function prints the vector by using print_cols elements on every line
*   with col_width being the width of the column. Basically it prints the table
*   of values from the vector.
*
*   @param v: Refrence for vector
*   @param print_cols: Number of columns
*   @param col_width: Width of the columns
*/
void print_vector(const std::vector<int>& v, int print_cols, int col_width)
{
    // for loop to print the header dashes of the table
    for (int i = 0; i < print_cols; i++)
    {
        cout << "-----";
    }
    cout << "---------------\n";

    // prints the numbers from the vector (v) and formats them with | padding
    for (unsigned int i = 0; i < v.size(); i++)
    {
        // if statement to print out 16 numbers on a single line
        if (i % print_cols == 0 && i != 0)
        {
            cout << endl; // then we create a new line
        }
        cout << "|" << setw(col_width) << v[i] << " "; // sets the proper formatting between numbers
    }
    // for loop to print out the remaining spaces with | on the last line
    for (int i = 0; i < 8; i++)
    {
        cout << "|" << setw(5) << " ";
    }
    cout << endl;

    // for loop to print bottom dashes of the table
    for (int i = 0; i < print_cols; i++)
    {
        cout << "-----";
    }
    cout << "---------------\n";
}

/**
*   @brief: Implements the sort algorithm to sort the vector that contains
*   values.
*
*   @param v: Reference for vector
*/
void sort_vector(std::vector<int>& v)
{
    // use the sort function to sort the vector by using begin and end 
    sort(v.begin(), v.end());
}

/**
*   @brief: Implements a search algorithm which uses a pointer to search the
*   routine p() for every element in v2 for v1. It also counts the number of
*   successful searches and returns that value which is returnned value that
*   will be passed to the print_stat() function.
*
*   @param v1: Refrence for vector a from main
*   @param v2: Refrence for vector b from main
*   @param bool (*p): Pointer to search the value in routine p
*
*   @return: It returns the number of our target value found
*/
int search_vector(const std::vector<int>& v1, const std::vector<int>& v2, bool (*p)(const std::vector<int>&, int))
{
    int count = 0; // tracks the number of counts

    for (size_t i = 0; i <= v2.size(); i++)
    {
        p(v1, v2[i]);
        count++; // then add when value found
    }
    return count;
}

/**
*   @brief: Prints the successful percentage for the total number of successful
*   searches.
*
*   @param total: Size of the test vector that is searched
*   @param found: Total number of successful searches
*/
void print_stat(int found, int total)
{
    double result = 0; // stores the percentage here

    //calculates the percentage of successful searches
    result = double(found / total) * 10;

    //print stament of result for the linear search and binary search
    cout << " Percent of Successful searches = " << fixed << setprecision(2) << result << "%" << endl;
}

/**
*   @breif: A linear search algorithm that searches the vector for the
*   value of x from the beginning to end. If the search was successful then
*   it will return true otherwise false.
*
*   @param v: Refrence for vecotor
*   @param x: The search value that will be searched in vector v
*
*   @return: Returns whether the value is found or not
*/
bool linear_search(const std::vector<int>& v, int x)
{
    /* implements a iterator to iterate through the vector to search the
       value x from the beginning to end. find() function locates the value.
    */
    vector<int>::const_iterator it;
    it = find(v.begin(), v.end(), x);
    if (it != v.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
*   @breif: A binary search algorithm where it searches the value x in
*   vector v
*
*   @param v: Vector that will be searched
*   @param x: the value being searched in the vector
*
*   @return: Returns true if found otherwise false
*/
bool binary_search(const std::vector<int>& v, int x)
{
    if (binary_search(v.begin(), v.end(), x))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
* Parse the command-line args, create and sort vector A, create vector B,
* search vector A for those elements appearing in vector B using both
* a linear and binary search, and print the hit-rate (the percentage of
* items in B that have been located in A.)
*
* If an invalid command-line arg is encountered, print a Usage statement
* and terminte with an exit-status of 1.
*
* @return zero
******************************************************************************/
int main(int argc, char** argv)
{
    // Demonstrate the use of getopt() to override default config parameters 
    int rand_low = 1;
    int rand_high = 1000;
    int a_size = 200;
    int b_size = 100;
    int a_seed = 1;
    int b_seed = 3;
    int print_cols = 16;
    int col_width = 4;

    int opt;
    // see: http://faculty.cs.niu.edu/~winans/CS340/2022-sp/#getopt
    while ((opt = getopt(argc, argv, "a:b:c:h:l:w:x:y:")) != -1)
    {
        switch (opt)
        {
        case 'a':
            // see https://en.cppreference.com/w/cpp/string/basic_string/stol
            a_size = std::stoi(optarg); // override the default for a_size
            break;

        case 'b':
            b_size = std::stoi(optarg);
            break;
        case 'c':
            print_cols = std::stoi(optarg);
            break;
        case 'h':
            rand_high = std::stoi(optarg);
            break;
        case 'l':
            rand_low = std::stoi(optarg);
            break;
        case 'w':
            col_width = std::stoi(optarg);
            break;
        case 'x':
            a_seed = std::stoi(optarg);
            break;
        case 'y':
            b_seed = std::stoi(optarg);
            break;

        default:
            // got an arg that is not recognized...
            usage(argv[0]);     // pass the name of the program so it can print it
        }
    }

    // Make sure there are not any more arguments (after the optional ones)
    if (optind < argc)
        usage(argv[0]);

    // Add application logic here...
    std::vector<int> a(a_size);
    std::vector<int> b(b_size);

    //First we initialize the vector a and vector b with random values which the function
    //by passing the parameters to it. Generates between 1 and 1000.
    init_vector(a, a_seed, rand_low, rand_high);
    init_vector(b, b_seed, rand_low, rand_high);

    //Prints out vector a with random numbers
    std::cout << "A vector: " << std::endl;
    print_vector(a, print_cols, col_width);

    //Here we print a sorted vector a by utilizing the sort function
    std::cout << "\nA Vector Sorted: " << std::endl;
    sort_vector(a);
    print_vector(a, print_cols, col_width);

    //Now we print the vector b with the random numbers
    std::cout << "\nB vector: " << std::endl;
    print_vector(b, print_cols, col_width);

    //Prints vector b that is sorted
    std::cout << "B Vector Sorted: " << std::endl;
    sort_vector(b);
    print_vector(b, print_cols, col_width);

    //Runs the test for linear search and prints the percentage result
    int linearSearch = search_vector(a, b, linear_search);
    cout << "Linear Search:";
    print_stat(linearSearch, b_size);

    //Runs the test for binary search and prints the percentage result
    int binarySearch = search_vector(a, b, binary_search);
    cout << "Binary Search:";
    print_stat(binarySearch, b_size);
} // End of main()

