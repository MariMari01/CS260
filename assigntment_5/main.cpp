#include <iostream>
#include "auto_ordered_list.hpp"


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
    Auto_ordered_list ordered_list;
    enum choices{insert = 1, remove, search, display, quit};

    do
    {
        show_menu();
        choice = get_int();
        
        switch (choice)
        {
            case insert:
            {
                cout << "What value will this node have?" << endl;
                node_value = get_int();
                ordered_list.insert(node_value);
                break;
            }
            case remove:
            {
                cout << "Remove what value?" << endl;
                node_value = get_int();
                ordered_list.remove(node_value);
                break;   
            }
            case search:
            {
                cout << "What valuse would you like to search for?" << endl;
                node_value = get_int();
                cout << ordered_list.search(node_value) << " Nodes with the value " << node_value << "found" << endl;
            }
                break;
            case display:
            {
                ordered_list.display();
                break;
            }
            case quit:
                ordered_list.~Auto_ordered_list();
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
            "|    [1] insert Node to list                            |" << endl <<
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
