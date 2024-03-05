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
    Binary_tree_destroyer(this->root);
}

/* Destructor helper function. */
void Binary_tree::Binary_tree_destroyer(Node*&current)
{
    if (current == nullptr)
    {
        return;
    }
    else
    {
        //Keep going until you hit node that is a leaf
        //D E S T R O Y!!! from there
        Binary_tree_destroyer(current->left);
        Binary_tree_destroyer(current->right);
        delete current;
        current = nullptr; 
    }
}


/* Adds a new node to the binary tree. */
void Binary_tree::add(int data)
{
    this->root = add_helper(this->root, data);
}

/* Helper for add method. */
Node* Binary_tree::add_helper(Node* current, int data)
{
    //When spot if empty, set it to a new node holding the given data.
    if (current == nullptr)
    {
        current = new Node;
        current->data = data;
        current->left = nullptr;
        current->right = nullptr;
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


/* Removes a node with the matching given data. */
void Binary_tree::remove(int data)
{
    remove_helper(this->root, data);
}

/* Helper for remove method. */
void Binary_tree::remove_helper(Node*&current, int data)
{
    /* If we reach the end of the tree, the given Node does not exist */
    if (current == nullptr)
    {
        return;
    }
    else if(data < current->data)
    {
        remove_helper(current->left, data);
    }
    else if(data > current->data)
    {
        remove_helper(current->right, data);
    }
    else
    {
        //If either left/right is nullptr, move the other one up to the current nodes place
        if (current->left == nullptr)
        {
            Node* right = current->right;
            delete current;
            current = right;
        }
        else if (current->right == nullptr)
        {
            Node* left = current->left;
            delete current;
            current = left;
        }
        else
        {
            //Look for the next smallest value after the current
            Node* next_smallest = current->right;
            while (next_smallest->left != nullptr)
            {
                next_smallest = next_smallest->left;
            }
            //Convert the current node into the next smallest and delete next smallest by starting to current's right
            current->data = next_smallest->data;
            remove_helper(current->right, next_smallest->data);
        }
    }
}


/* Prints out the Nodes in order. */
void Binary_tree::io_traversal()
{
    io_traversal_helper(this->root);
}

/* Helper function for In Order Traversal. */
void Binary_tree::io_traversal_helper(Node* current)
{
    //return after we reach the left most node - the one with the smallest value.
    if (current == nullptr)
    {
        return;
    }
    //Keep going if there is a smaller value.
    io_traversal_helper(current->left);
    //Print value.
    cout << current->data << " ";
    //Check any right nodes after checking all of the left most nodes.
    io_traversal_helper(current->right);
}

// void Binary_tree::bf_traversal()
// {
//     if (current->left != nullptr || current->right != nullptr)
//     {
//         cout << current->data << " ";
//     }
// }
