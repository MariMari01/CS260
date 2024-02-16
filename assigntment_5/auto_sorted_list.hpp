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

class Auto_ordered_list
{
    Node *head;
    Node *tail; 

public:
    Auto_ordered_list();
    ~Auto_ordered_list();
    void insert(int value);
    int remove(int value);
    int search(int value);
    void display();
};
