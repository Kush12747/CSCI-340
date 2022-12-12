/**
 *  Kush Gandhi
 *  z1968933 
 *  CSCI 340-PE1 section Harper
 *  9/26/22
 * 
 *  I certify that this is my own work and where appropriate an extension
 *  of the starter code provided for the assignment.
*/

#ifndef STACK_H
#define STACK_H
#include <queue>

template<typename T>
class Stack
{
private:
    std::queue<T> q1;	// These queues are where the stack's elements 
    std::queue<T> q2;	// are to be saved.

public:
    bool empty() const;
    int size() const;
    const T& top();
    void push(const T &val);
    void pop();
};


// Note that the members of a template go into a .h file since 
// they are not compiled directly into a .o file like the members 
// of regular/non-template classes.




// Place your Stack class member implementations here.

/**
 *  @brief: This function here is checking if the queue is empty or not.
 * 
 *  @return: Returns true if empty owtherwise false when not empty.
*/
template<typename T>
bool Stack<T>::empty() const
{
    if (q1.empty())
    {
        return true;
    }
    else 
    {
        return false;    
    }
}

/**
 *  @brief: This function here checks the size of the queue and returns
 *  the amount of elements in it.
 * 
 *  @return: Returns the number of elements in the queue.
*/
template<typename T>
int Stack<T>::size() const
{
    return q1.size();
}

/**
 *  @brief: This function here gets the refrence of the newest element.
 * 
 *  @return: Returns the the newest element in the queue
*/
template<typename T>
const T& Stack<T>::top()
{
    return q1.front();
}

/**
 *  @brief: This function pushes the number to the queue
 *  by using both queues.
 * 
*/
template<typename T>
void Stack<T>::push(const T &val)
{
    while (!q1.empty())
    {
	q2.push(q1.front());
	q1.pop();
    }

    q1.push(val);

    while (!q2.empty())
    {
        q1.push(q2.front());
	q2.pop();
    }
}

/**
 *  @brief: This function pops which removes the newest element in the queue.
*/
template<typename T>
void Stack<T>::pop()
{
    if (q1.empty())
    {
        return;
    }
    else
    {
        q1.pop();
    }
}

#endif //STACK_H
