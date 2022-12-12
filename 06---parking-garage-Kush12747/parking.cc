/**
*   Kush Gandhi
*   z1968933
*   CSCI-340 section Harper
*   10/17/22
*   Assignment 6
*   
*   I certify that this is my own work and where appropiate an
*   extension of the starter code provided for the assignment
*/
#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>

#include "car.h"
#include "garage.h"

using namespace std;

/**
*   @brief: This function here extracts the components from the input file
*   that containes license plates.
* 
*   @param line: extract the componets from input
*   @param xact_type: indicates if the car for arrivial and depature
*   @param license: License plate number for arrivial and departure
*/
void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
    string checkArrival = line.substr(0, 1);
    license = line.substr(2, line.length() - 3);
}

/**
*   @brief: This function prints the arrival of the car. If the garage is full then
*   print the message otherwise, add it to the deque.
* 
*   @param license: license of the car
*/
void garage::arrival(const std::string& license)
{
    garage car; //define object

    //print statement for arrival of cars
    cout << "Car " << next_car_id <<  " with license plate " << '"' << license << '"' << " has arrived." << endl << endl;

    ++next_car_id; //increment number of cars

    //checks if garage is full
   if (next_car_id == parking_lot_limit)
   {
       cout << "\tBut the garage is full!" << endl;
   }
   else
   {
       deque<string> parking_lot;
       parking_lot.push_back(license);
   }
}

/**
*   @brief: This functions checks the car elements in the deque to check for
*   given license. If not then we print message saying it's full. Otherwise, if
*   found we move the car elements out of the degue and into stack<car>
* 
*   @param license: license of the car
*/
void garage::departure(const std::string &license)
{
    //prints the departure
    cout << "Car " << next_car_id << " with license plate " << "'" << license << "'" << " has departed," << endl << endl;
	
    //loop to check the licenses in the deque
    for (auto it = parking_lot.begin(); it != parking_lot.end(); it++)
    {
	/*if (parking_lot.front== parking_lot.end())
	{
	    stack<string> temp;
	    temp.push(license);
	}
	else
	{
	    cout << "\n\tBut the garage is full!" << endl;
	}*/
    }
}

int main()
{
    garage g; //object for garage class
    string input; //reads in input from fil
    char checkArrival; //checks if arrival or departure
  
    //loop to get input from the file
    while (getline(cin, input))
    {
	string plateNumber = input.substr(2,input.length()-3);
	if (input.substr(0,1) == "A")
	{
	    //function calls
	    checkArrival = input.at(0);
	    g.arrival(plateNumber);
	    get_input_vals(input, checkArrival, input);
	}
	else if (input.substr(0, 1) == "D") 
	{
	   get_input_vals(input, checkArrival, input);
	   g.departure(plateNumber);
	}
	else
	{
	    cout << "'X': invalid action!" << endl << endl;
	}
    }
}
