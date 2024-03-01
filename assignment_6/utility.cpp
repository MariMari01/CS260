#include <iostream>
using std::cout;
using std::endl;
/*-------------------------------------------- UTILITY FUNCTIONS ---------------------------------------------- */

/* Shows the user menu containting choices */
void show_menu()
{
    cout << endl <<
            "------------------------------------------------------" << endl <<
            "|                                                    |" << endl <<
            "|  Welcome! This program represents a binary tree    |" << endl <<
            "|                                                    |" << endl <<
            "|    [1] Add                                         |" << endl <<
            "|    [2] Remove                                      |" << endl << 
            "|    [3] In order traversal                          |" << endl <<
            "|    [4] Breadth First traversal                     |" << endl <<
            "|    [5] Quit                                        |" << endl <<
            "|                                                    |" << endl <<
            "------------------------------------------------------"  << endl;
}

//Clears the buffer for scanf
void clear_buffer(int ch)
{
    while(ch = getchar() != '\n' && ch != EOF);
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

