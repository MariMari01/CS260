
#include "linked_list.hpp"

/* --------------------------------------------- NODE DEFINITION --------------------------------------------------- */

Node::Node()
{
    this->data = 0;
    this->position = 0;
    this->next = nullptr;
}

/* -------------------------------------------- LINKED LIST DEFINITION -------------------------------------------- */

Linked_list::Linked_list()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

/* ------------------------------------------------ LINKED LIST METHODS ------------------------------------------- */
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
        Node *temp_node = this->head;
        while (temp_node->position <= new_node->position && temp_node->next != nullptr)
        {
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
        new_node->next = temp_node->next;
        temp_node->next = new_node;
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


