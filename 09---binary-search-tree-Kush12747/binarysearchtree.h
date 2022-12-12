/**
*   Kush Gandhi
*   z1968933
*   CSCI-340 section harper
*   Assignment 9
*   11/14/22
*   
*   I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "node.h"
#include "btree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T& x);       // inserts node with value x
    bool Search(const T& x) const; // searches leaf with value x
    bool Remove(const T& x);       // removes leaf with value x
private:
    void _Insert(Node<T>*&, const T&);      // private version of insert
    bool _Search(Node<T>*, const T&) const; // private version of search
    void _Remove(Node<T>*&, const T&);      // private version of remove
    bool _Leaf(Node<T>* node) const;          // checks if node is leaf
};

/**
*   @brief: This function calls the private version of _Insert()
*   to insert a node.
*
*   @param x: value of x being inserted
*/
template <typename T>
void BinarySearchTree<T>::Insert(const T& x)
{
    _Insert(this->root, x);
}

/**
*   @brief: This function calls the private version of _Search()
*   to search the leaf.
*
*   @param x: value of x being searched
*
*   @return: returns true if found or false
*/
template <typename T>
bool BinarySearchTree<T>::Search(const T& x) const
{
    return _Search(this->root, x);
}

/**
*   @brief: This function removes a leaf with the value x.
* 
*   @param x: value being deleted
* 
*   @return: Returns true if deleted else false
*/
template <typename T>
bool BinarySearchTree<T>::Remove(const T& x)
{
    //calls the search function to search x and returns true or false
    if (Search(x))
    {
        _Remove(this->root, x);
	return true;
    }
    else
    {
	this->root = NULL;
	return false;
    }
}

/**
*   @brief: This function inserts a node in the tree.
*
*   @param node: node in the tree
*   @param x: value being inserted
*/
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T>*& node, const T& x)
{
    //if no node then make a new node else check if > or < to insert node
    if (node == NULL)
    {
        Node<T>* temp = new Node<T> (x);
        node = temp;
    }
    else if (x > node->data)
    {
        _Insert(node->right, x);
    }
    else 
    {
        _Insert(node->left, x);
    }
}

/**
*   @brief: This function searches for value x in the tree.
* 
*   @param node: node in the tree
*   @param x: value being searched
* 
*   @return: Returns true if search is successfull else false
*/
template <typename T>
bool BinarySearchTree<T>::_Search(Node<T>* node, const T& x) const
{
    //if null then return false
    if (node == NULL)
    {
        return false;
    }
   
    //if node matches the value x then true
    if (node->data == x)
    {
	if (_Leaf(node)) //checks if node is a leaf
	{
	    return true;
	}
	else
	{
	    return false;
	}
    }

    //checks if x is greater then search right side else search left side    
    if (x > node->data)
    {
        return _Search(node->right, x);
    }
    else
    {
        return _Search(node->left, x);
    }
}

/**
*   @brief: This function removes the leaf corresponding value of x.
*
*   @param node: node in the tree
*   @param x: value being removed
*/
template <typename T>
void BinarySearchTree<T>::_Remove(Node<T>*& node, const T& x)
{
    //to remove then set node to null
    if (x > node->data)
    {
	//delete(node);
        node->right = NULL;;
    }
    else
    {
        node->left = NULL;
    }
}

/**
*   @brief: This function checks whether the node is a leaf
*   by checking left and right sides.
*
*   @param node: node in the tree
*
*   @return: returns true if node is a leaf else false
*/
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T>* node) const
{
    //check if right and left sides are null then it is a leaf
    if (node->left == NULL && node->right == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif // End of BINARYSEARCHTREE_H_

