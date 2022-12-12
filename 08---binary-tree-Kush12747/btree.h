/**
*   Kush Gandhi
*   CSCI-340
*   Assignment 8
*   11/7/22
*   
*   I certify that this is my own work and where and appropiate an
*   extension of the starter code provided for the assignment.
*/
#ifndef H_BTREE
#define H_BTREE

#include "node.h"
#include <algorithm>

template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorde
};

//implentation of randomly inserting a node either right ot left
typedef enum { left_side, right_side } SIDE;

SIDE rnd() {
    return rand() % 2 ? right_side : left_side;
}// End of rnd()

/**
*   @brief: The defualt constructor for the binary tree to
*   set the root of thr tree to null.
*/
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

/**
*   @brief: This function calls the private version of _getSize().
*
*   @return: calls the private version
*/
template <typename T>
unsigned BinaryTree<T>::getSize() const
{
    return _getSize(root);
}

/**
*   @brief: This function calls the private version of _getHeight().
*
*   @returns: calls the private version
*/
template <typename T>
unsigned BinaryTree<T>::getHeight() const
{
    return _getHeight(root);
}

/**
*   @brief: This function calls the private version of _Insert()
*   by passing in the root and value.
*
*   @param x: x is the value being inserted into the tree by calling
*   the private version of the function
*/
template <typename T>
void BinaryTree<T>::Insert(const T& x)
{
    _Insert(root, x);
}
/**
 *  @brief: This function calls the private version of _Inorder()
 *
 *  @param *p: pointer
*/
template <typename T>
void BinaryTree<T>::Inorder(void(*p)(const T&))
{
    _Inorder(root, p);
}

/**
*   @breif: This function gets the size of the tree by recursively to count
*   the root and the nodes in the left and right subtrees.
*
*   @param node: node in the tree
*
*   @return: returns the size of the tree by adding the root + left nodes + right 
*   nodes recursively
*/
template <typename T>
unsigned BinaryTree<T>::_getSize(Node <T>* node) const
{
    //check if null, if not then recursively call left and right sides
    if (node == NULL)
    {
	return 0;
    }
    else
    {
	// 1 for root and add left and right nodes
	return 1 + (_getSize(node->left) + _getSize(node->right));
    }
}

/**
*   @brief: This function gets the height of the tree by recursively
*   left side and the right side.
*
*   @param node: node in  the tree
*
*   @return: Returns the height of the tree
*/
template <typename T>
unsigned BinaryTree<T>::_getHeight(Node <T>* node) const
{
    //check if null then recursively get the max height either left or right
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(_getHeight(node->left), _getHeight(node->right));
    }

}

/**
*   @brief: This function inserts a new node into the tree.
*
*   @param x: data value being inserted
*   @param node: node in the tree
*/
template <typename T>
void BinaryTree<T>::_Insert(Node<T>*& node, const T& x)
{
    //if node null then create a new node
    if (node == NULL)
    {
	//make a new node to insert x in the tree
	Node<T>* temp = new Node<T>(x);
	node = temp; //set new node
    }
    else
    {
	//rnd(); //call rnd() 
	//determine which side the node will fall based on rnd()
	if (rnd() == left_side)
	{
	    _Insert(node->left, x);
	}
	else
	{
	    _Insert(node->right, x);
	}
    }
}

/**
*   @brief: This function performs a inorder traversal
*
*   @param node: node of the tree
*   @param *p: pointer
*/
template <typename T>
void BinaryTree<T>::_Inorder(Node<T>* node, void (*p)(const T&))
{
    //if not null than perform inorder travseral (left,node,right)
    if (node != NULL)
    {
        _Inorder(node->left, p); //left
        p(node->data);           //node
        _Inorder(node->right, p);//right
    }
}
#endif // End of H_BTREE
