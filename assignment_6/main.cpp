#include <iostream>
#include "binary_tree.hpp"
#include "utility.hpp"
using std::cout;
using std::endl;
/*
Author: Samuel Garcia Lopez
Date: 2.29.24
*/

int main()
{
    Binary_tree tree;
    bool exit = false;
    int choice, data;
    enum choices{add = 1, remove, in_order, breadth_first, quit};

    do
    {
        show_menu();
        choice = get_int();
        //User choice
        switch (choice)
        {
            case add:
            {
                cout << "What value will this node have?" << endl;
                data = get_int();
                tree.add(data);
                break;
            }
            case remove:
            {
                cout << "Remove what value?" << endl;
                data = get_int();
                tree.remove(data);
                break;   
            }
            case in_order:
            {
                tree.io_traversal();
                break;
            }
            case breadth_first:
            {
                break;
            }
            case quit:
            {
                exit = true;
                tree.~Binary_tree();
                break;  
            }
            default:
            {
                cout << "Error - Wrong input" << endl;
                break;
            }
        }
    } while (exit == false);
    return 0;
}
