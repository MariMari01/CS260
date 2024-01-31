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
    int size;
    public:
        Queue();
        void enqueue(int data);
        int dequeue();
        void peek();
};
