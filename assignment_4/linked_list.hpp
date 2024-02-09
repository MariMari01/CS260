#include <string>
/* Initiates Node class */
class Node
{
    public:
        Node();
        int position;
        int data;
        Node* next;
        std::string to_string();
};

class Linked_list
{
    Node *head;
    Node *tail; 
    int size;
public:
    Linked_list();
    ~Linked_list();
    void add(int value, int position);
    void display();
    int remove(int position);
    int get(int position);
};
