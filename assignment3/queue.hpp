#include <string>
/* Initiates Node class */
class Node
{
    public:
        Node();
        int ID;
        int data;
        Node* next;
        std::string to_string();
};


/* Initiates Queue class */
class Queue
{
    Node* front;
    int size;
    public:
        Queue();
        void enqueue(int data);
        int dequeue();
        void peek();
        void delete_queue();
};
