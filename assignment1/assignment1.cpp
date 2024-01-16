/* 
Author: Samuel Garcia Lopez
Date: Jan 15, 2024
This file represents a bag full of marbles, the user can add or take away marbles
of the colors red and blue. They can also view how many marbles they have in total
as well as how any of each color.  
 */

#include <iostream>
using std::cout;
using std::endl;

void clear_buffer(int ch);
int get_int();
void show_menu();

int main()
{
    bool run = true, red_blue = true;
    enum choices{add = 1, take_out, count, quit};
    int marbles = 0, red = 0, blue = 0, ch;
    int choice;
    
    do
    {
        show_menu();
        choice = get_int();

        switch(choice)
        {
        case add:
            //ask user how many marbles to add
            cout << endl << "Add how many marbles?" << endl;
            marbles = get_int();
            cout << endl << "Red[1] or blue[2]?" << endl;
            //ask user whenever to add red or blue marbles
            red_blue = true;
            do
            {
                choice = get_int();

                if (choice == 1)
                {   red += marbles;
                    red_blue = false;
                }
                else if (choice == 2)
                {
                    blue += marbles;
                    red_blue = false;
                }
                else
                    cout << endl << "Invalid Input" << endl;         
            }while (red_blue);
            break;
        case take_out:
            //ask user how many marbles to take
            cout << endl << "Take out how many marbles?" << endl;
            marbles = get_int();
            cout << endl << "Red[1] or blue[2]?" << endl;
            
            //ask user whenever to add red or blue marbles
            red_blue = true;
            do
            {
                choice = get_int();
                if (choice == 1)
                {   red -= marbles;
                    red_blue = false;
                }
                else if (choice == 2)
                {
                    blue -= marbles;
                    red_blue = false;
                }
                else
                    cout << endl << "Invalid Input" << endl; 
            }while (red_blue);
            
            //ensures that you cannot have negative marbles of either color
            if (red < 0)
                red = 0;
            else if (blue < 0)
                blue = 0;
            break;
        case count:
            //counts the marbles inside the user's bag
            if (red + blue == 0)
                cout <<endl << "The marble bag is empty" << endl;
            else
                cout << endl << "You have " << red + blue << " marbles in your bag" << endl
                << "Red marbles: " << red << endl
                << "Blue marbles: " << blue << endl;
            break;
        case quit:
            //lets the user quit
            run = false;
            break;

        default:
            cout << "Error - invalid input" << endl;
        }
    }while (run);
}



/* Brings up the user menu */
void show_menu()
{
    cout << endl
    << "[-----Enter what you wish to do-----]" << endl 
    << "[1. Add Marble                      ]" << endl 
    << "[2. Take out Marble                 ]" << endl 
    << "[3. Count Marbles                   ]" << endl
    << "[4. Quit                            ]" << endl;
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
