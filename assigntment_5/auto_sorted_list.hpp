#include <string>
/* Initiates Node class */
class Node
{
    public:
        Node();
        int data;
        Node* next;
        std::string to_string();
};

class Auto_sorted_list
{
    Node *head;
    Node *tail; 

public:
    Auto_sorted_list();
    ~Auto_sorted_list();
    void insert(int value);
    int remove(int value);
    int search(int value);
    void display();
};
