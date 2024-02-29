#include <string>
using std::string;
/* This file initializes Node and Binary tree */
class Node
{
    public:
        Node();
        int data;
        Node* left;
        Node* right;

        string to_string();
};

class Binary_tree
{
    private:
        Node* root;

        Node* add_helper(Node* current, int data);
        Node* remove_helper(Node* current, int data);  
    public:
        Binary_tree();
        ~Binary_tree();

        void add(int data);
        void remove(int data);

        void io_traversal();
        void pos_traversal();
        void pre_traversal();
        void bf_traversal();
};
