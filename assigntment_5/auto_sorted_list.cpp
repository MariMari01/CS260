#include <iostream>
#include "auto_ordered_list.hpp"
using std::string;

/* --------------------------------------------- NODE DEFINITION --------------------------------------------------- */

Node::Node()
{
    this->data = 0;
    this->next = nullptr;
}

string Node::to_string()
{
    /* Displays node values. */
    string result = 
    "\nData: " + std::to_string(this->data) +
    "\nNext: " + std::to_string((long long)(this->next)) + "\n";
    
    return result;
}
/* -------------------------------------------- LINKED LIST DEFINITION -------------------------------------------- */

Auto_ordered_list::Auto_ordered_list()
{
    this->head = nullptr;
    this->tail = nullptr;
}



/* Adds a new Node to the list in order */
void Auto_ordered_list::insert(int value)
{
    Node *new_node = new Node;
    new_node->data = value;

    //If list is empty, the new node will be the head.
    if (this->head == nullptr && this->tail == nullptr)
    {
        this->head = new_node;
        this->tail = new_node;
    } 
    
    //If the node's value is larger than the tail, it becomes the new tail.
    else if (new_node->data > this->tail->data)
    {
        this->tail->next = new_node;
        this->tail = new_node;
    }

    //If the node's value is smaller than the head's
    else if (new_node->data < this->head->data)
    {
        new_node->next = this->head;
        this->head = new_node;
    }

    //Searches through the linked list for the new node's position
    else
    {   
        //Seach for where to insert the node
        Node *temp_node = this->head;
        while (temp_node->data <= new_node->data && temp_node->next != nullptr)
        {
            temp_node = temp_node->next;
        }
        new_node->next = temp_node->next;
        temp_node->next = new_node;

    }
}


/* Deletes all nodes with a certain value from the list. */
void Auto_ordered_list::remove(int value)
{
    Node *temp_node;
    temp_node = this->head;
    Node *previous;
    
    //Begin searching for the node.
    while (temp_node != nullptr)
    {
        if (temp_node->data == value)
        {
            if (temp_node == this->head)
            {
                this->head = temp_node->next;
                delete temp_node;
                temp_node = this->head;
            }
            else
            {
                previous->next = temp_node->next;
                delete temp_node;
                temp_node = previous->next;
            }
        }
        previous = temp_node;
        temp_node = temp_node->next;       
    }
}


/* Returns the amount of times a value shows up in the linked list. */
int Auto_ordered_list::search(int value)
{
    int count = 0;
    Node *temp_node = this->head;

    while (temp_node != nullptr)
    {
        if (temp_node->data == value)
            count++;
        temp_node = temp_node->next;
    }
    return count; 
}


//Displays all values present within the linked list.
void Auto_ordered_list::display()
{
    Node *temp = this->head;
    while (temp != nullptr)
    {
        std::cout << temp->to_string();
        temp = temp->next;
    }
}

//Deletes the linked list.
Auto_ordered_list::~Auto_ordered_list()
{
    Node *temp;
    while (this->head != nullptr)
    {
        temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}
