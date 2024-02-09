
#include <iostream>
#include "linked_list.hpp"


using std::cout;
using std::endl;

//Utility functions
void show_menu();
void clear_buffer(int ch);
int get_int();

int main()
{
    bool exit = false;
    int choice, node_position;
    Linked_list arbritary_list;
    enum choices{add = 1, remove, get, display, quit};

    do
    {
        show_menu();
        choice = get_int();
        
        switch (choice)
        {
            case add:
            {
                cout << "What value will this node have?" << endl;
                int node_value = get_int();
                cout << "What position will this node be added to?" << endl;
                node_position = get_int();
                arbritary_list.add(node_value, node_position);
                break;
            }
            case remove:
            {
                cout << "Remove what position?" << endl;
                node_position = get_int();
                cout << "Node with value of " << arbritary_list.remove(node_position) << " removed." << endl;
                break;   
            }
            case get:
            {
                cout << "What is the node's positon that you want to get?" << endl;
                node_position = get_int();
                cout << "Nodes value: " << arbritary_list.get(node_position) << endl;
            }
                break;
            case display:
            {
                arbritary_list.display();
                break;
            }
            case quit:
                arbritary_list.~Linked_list();
                exit = true;
                break;  
            default:
                cout << "Error - Wrong input" << endl;
                break;
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
            "|    [1] Add Node to list                            |" << endl <<
            "|    [2] Remove Node from list                       |" << endl << 
            "|    [3] Get value of Node from list                 |" << endl <<
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
