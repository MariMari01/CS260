#include <string>
class Node
{
    public:
        Node();
        int ID;
        int data;
        Node* next;
        std::string to_string();
};



class Queue
{
    Node* front;
    Node* back;
    int size;
    
    public:
        Queue();
        void enqueue(int data);
        int dequeue();
        int peek()
};

