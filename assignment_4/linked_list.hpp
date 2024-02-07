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

class linked_list
{
    Node *new_node;
public:
    linked_list();
    ~linked_list();
    void add(int value, int position);
    int remove(int position);
    int get(int position):
};
