#include <iostream>
#include "auto_sorted_list.hpp"
/*
Author: Samuel Garcia Lopez
Date: 2.16.24
This program is an auto-sorted linked list. The linked list will sort itself using the value of the nodes
that are added at the moment they are added.

The worst case scenario for the number of operations to find where to add the node will be O(n). In the best case scenario it will be O(1).
*/

using std::cout;
using std::endl;

//Utility functions
void show_menu();
void clear_buffer(int ch);
int get_int();

int main()
{
    bool exit = false;
    int choice, node_value;
    Auto_sorted_list sorted_list;
    enum choices{insert = 1, remove, search, display, quit};

    do
    {
        show_menu();
        choice = get_int();
        //User choice
        switch (choice)
        {
            case insert:
            {
                cout << "What value will this node have?" << endl;
                node_value = get_int();
                sorted_list.insert(node_value);
                break;
            }
            case remove:
            {
                cout << "Remove what value?" << endl;
                node_value = get_int();
                int removed_pos = sorted_list.remove(node_value);
                if (removed_pos == -1)
                    cout << "No Node with that value found" << endl;
                else
                    cout << "Node with value " << node_value << " removed at position " << removed_pos << "." << endl;
                break;   
            }
            case search:
            {
                cout << "What valuse would you like to search for?" << endl;
                node_value = get_int();
                cout << sorted_list.search(node_value) << " Nodes with the value " << node_value << " found" << endl;
            }
                break;
            case display:
            {
                sorted_list.display();
                break;
            }
            case quit:
            {
                sorted_list.~Auto_sorted_list();
                exit = true;
                break;  
            }
            default:
            {
                sorted_list.~Auto_sorted_list();
                cout << "Error - Wrong input" << endl;
                break;
            }
        }
    } while (exit == false);
    return 0;
}

/*-------------------------------------------- UTILITY FUNCTIONS ---------------------------------------------- */

/* Shows the user menu containting choices */
void show_menu()
{
    cout << "------------------------------------------------------" << endl <<
            "|                                                    |" << endl <<
            "|    Welcome! This program uses an arbritary list    |" << endl <<
            "|                                                    |" << endl <<
            "|    [1] Insert Node to list                         |" << endl <<
            "|    [2] Remove Node from list                       |" << endl << 
            "|    [3] Search Nodes                                |" << endl <<
            "|    [4] Display all nodes                           |" << endl <<
            "|    [5] Quit                                        |" << endl <<
            "|                                                    |" << endl <<
            "------------------------------------------------------"  << endl;
}

/*Int input validation*/
int get_int()
{
    int ret, ch, user_choice;

    //While the input is not an integer
    do
    {
        //Prompt user for integer
        ret = scanf("%d", &user_choice);
        clear_buffer(ch);
        //If return value is not an integer, raise error and prompt again
        if (ret != 1)
            puts("ERROR - Please enter a number");
    } while (ret != 1);

    return user_choice;
}

//Clears the buffer for scanf
void clear_buffer(int ch)
{
    while(ch = getchar() != '\n' && ch != EOF);
}
