#include <iostream>
#include "Binary_tree.hpp"
using std::cout;

/* Node constructor. */
Node::Node()
{
    this->data = 0;

    this->right = nullptr;
    this->left = nullptr;
}
/* ---------------------------------------------------------------------------------------------------------------------- */

/* Binary tree constructor. */
Binary_tree::Binary_tree()
{
    this->root = nullptr;
}

/* Binary tree destructor. */
Binary_tree::~Binary_tree()
{
}


/* Adds a new node to the binary tree. */
void Binary_tree::add(int data)
{
    add_helper(this->root, data);
}

/* Helper for add method. */
Node* Binary_tree::add_helper(Node* current, int data)
{
    //When spot if empty, set it to a new node holding the given data.
    if (current == nullptr)
    {
        current = new Node;
        current->data = data;
    }
    else if (data <= current->data)
    {    //Go left and repeat process with that left node.
        current->left = add_helper(current->left, data);
    }
    else 
    {   //Go right and repeat process with that right node.
        current->right = add_helper(current->right, data);
    }
    return current;
}



void Binary_tree::remove(int data)
{

}


void Binary_tree::io_traversal()
{

}
