#include <iostream>
#include "linked_list.hpp"
using std::string;

/* --------------------------------------------- NODE DEFINITION --------------------------------------------------- */

Node::Node()
{
    this->data = 0;
    this->position = 0;
    this->next = nullptr;
}

string Node::to_string()
{
    /* Displays node values. */
    string result = 
    "\nPosition: "    + std::to_string(this->position) +
    "\nData: " + std::to_string(this->data) +
    "\nNext: " + std::to_string((long long)(this->next)) + "\n";
    
    return result;
}
/* -------------------------------------------- LINKED LIST DEFINITION -------------------------------------------- */

Linked_list::Linked_list()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}



/* Adds a new Node to the desired position. */
void Linked_list::add(int value, int position)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->position = position;

    //If list is empty, the new node will be the head.
    if (this->head == nullptr)
    {
        new_node->position = 0;
        this->head = new_node;
        this->tail = new_node;
    } 
    //If the nodes position is larger than the linked list it becomes the new tail of the list
    else if (new_node->position > this->tail->position)
    {
        new_node->position = this->tail->position + 1;
        this->tail->next = new_node;
        this->tail = new_node;
    }
    //If the node's position is smaller than that of the heads
    else if (new_node->position < this->head->position)
    {
        new_node->position = this->head->position - 1;
        new_node->next = this->head;
        this->head = new_node;
    }
    else
    {   
        //Seach for where to insert the node
        Node *previous;
        Node *temp_node = this->head;
        while (temp_node->position <= new_node->position && temp_node->next != nullptr)
        {
            previous = temp_node;
            temp_node = temp_node->next;
        }
        //If a node with the same position as an existing node is added, it will replace the existing node.
        if (temp_node->position == new_node->position)
        { 
            temp_node->data = new_node->data;
            delete new_node;
            this->size -= 1;
        }
        else
        {
            //Add the new node
            new_node->next = previous->next;
            previous->next = new_node;
        }
    }
    this->size += 1;
}


/* Deletes a node from the linked list at given position and returns its data value. */
int Linked_list::remove(int position)
{
    int ret_value;
    Node *temp_node;
    //If list is empty. return error
    if (this->head == nullptr)
    {
        puts("ERROR - linked list is empty.");
        return 0;
    }
    //If the position is the head, set head to the next value and delete the node. 
    else if (position == this->head->position)
    {
        ret_value = this->head->data;
        temp_node = this->head;
        this->head = this->head->next;

        delete temp_node;
    }
    else
    {
        temp_node = this->head;
        Node *previous;
        //Begin searching for the node.
        while (temp_node->position != position && temp_node != nullptr)
        {
            previous = temp_node;
            temp_node = temp_node->next;       
        }
        //If it reached the end of the list without finding the node.
        if (temp_node == nullptr)
        {
            puts("ERROR - no node with that position found.");
            return 0;
        }
        //If node is found. delete it.
        else
        {
            ret_value = temp_node->data;
            previous->next = temp_node->next;
            
            delete temp_node;
        }
    }
    //Return the saved return value. 
    return ret_value;
}


/* Gets a node's value without deleting the node */
int Linked_list::get(int position)
{
    if (this->head == nullptr)
    {
        puts("ERROR - list is empty.");
        return 0;
    }

    Node *temp_node = this->head;
    //Search for matching position.
    while (temp_node->position != position && temp_node->next != nullptr)
    {
        temp_node = temp_node->next;
    }
    
    if (temp_node->position != position)
    {
        puts("ERROR - could not find specified node position.");
        return 0;
    }
    else
    {
        return temp_node->data;
    }    
}



void Linked_list::display()
{
    Node *temp = this->head;
    while (temp != nullptr)
    {
        std::cout << temp->to_string();
        temp = temp->next;
    }
}


Linked_list::~Linked_list()
{
    Node *temp;
    while (this->head != nullptr)
    {
        temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}
