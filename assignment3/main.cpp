/* 
Author: Samuel Garcia Lopez
Date: 1.29.2024

This program represents a queue. New elements are added to the back of the queue, and elelments are
taken out from the front of th queue. 
 */ 
#include <iostream>
#include "queue.hpp"
using std::cout;
using std::endl;

void show_menu();
void clear_buffer(int ch);
int get_int();

int main()
{
    bool exit = false;
    int choice;
    Queue *node_queue; 
    enum choices{add = 1, remove, peek, quit};

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
            node_queue->enqueue(node_value);
            cout << "New node added to queue!"        << endl;
            break;
        }
        case remove:
        {
            node_queue->dequeue();
            cout << "Front node removed!" << endl;
            break;   
        }
        case peek:
        {
            
        }
            break;
        case quit:
            exit = true;
            break;  
        default:
            cout << "Error - Wrong input" << endl;
            break;
    }
} while (exit == false);
}





/* Shows the user menu containting choices */
void show_menu()
{
    cout << "------------------------------------------------------" << endl <<
            "|                                                    |" << endl <<
            "|  Welcome! This program will demonstrate a Queue    |" << endl <<
            "|                                                    |" << endl <<
            "|    [1] Add Node to Queue                           |" << endl <<
            "|    [2] Remove Node from Queue                      |" << endl << 
            "|    [3] Peek at front element                       |" << endl <<
            "|                                                    |" << endl <<
            "|                                                    |" << endl <<
            "-----------------------------------------------------"  << endl;
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


