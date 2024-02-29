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
    public:
        Binary_tree();
        ~Binary_tree();

        void add(int data);
        void remove(int data);

        int io_traversal(int data);
        int pos_traversal(int data);
        int pre_traversal(int data);
        int bf_traversal(int data);
};
