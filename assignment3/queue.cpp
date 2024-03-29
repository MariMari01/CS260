
#include <iostream>
#include "queue.hpp"
using std::string;
/*
This code defines the features and methods of the Node and Queue class. 
*/
/* ----------------------------------------------- NODE ------------------------------------------------------------ */
Node::Node()
{
    this->ID = 0;
    this->data = 0;
    this->next = nullptr;
}

string Node::to_string()
{
    /* Displays node values. */
    string result = 
    "ID: "    + std::to_string(this->ID) +
    ",Data: " + std::to_string(this->data) +
    ",Next: " + std::to_string((long long)(this->next));
    
    return result;
}

/* ----------------------------------------------- QUEUE ---------------------------------------------------------- */

Queue::Queue()
{ 
    this->front = nullptr;
    this->size = 0;
}

/* Adds a new node to the back of the Queue. */
void Queue::enqueue(int data)
{
    Node *new_node = new Node;
    new_node->ID = this->size;
    new_node->data = data;
    /* If the current Queue is empty, set the new Node to the front. */
    if (this->front == nullptr)
    {
        this->front = new_node;
    }/* If it is not empty, set the new node to be the next of the current final node. */
    else
    {
        Node *temp_node = this->front;
        while (temp_node->next != nullptr)
        {
            temp_node = temp_node->next;
        }
        temp_node->next = new_node;
    }
    this->size++;
}

/* Removes the oldest node from the front of the Queue. */
int Queue::dequeue()
{
    Node *to_be_deleted = this->front;
    this->front = front->next;
    delete to_be_deleted;
    this->size--;
    return 0;
}

/* Peeks at the Node at the front of the Queue. */
void Queue::peek()
{
    if (this->front == nullptr)
        std::cout << "the queue is empty!"    << std::endl;
    else
        std::cout << this->front->to_string() << std::endl;
}

/* Deletes all Nodes inside of the Queue. */
void Queue::delete_queue()
{
    while (this->front != nullptr && this->size != 0)
    {
        this->dequeue();
    }
}
