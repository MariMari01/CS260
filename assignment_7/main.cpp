#include <iostream>
#include <stdio.h>
#include "smart_hash.hpp"
#include "utility.hpp"
using std::cout;
using std:: cin;
using std::getline;
using std::endl;
/*
Author: Samuel Garcia Lopez
Date: 3.6.24
*/

int main()
{
    Hash_table table(40);
    bool exit = false;
    int choice;
    string key;
    enum choices{add = 1, remove, seach, display, quit};

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
                getline(cin, key);

                table.add(key);
                break;
            }
            case remove:
            {
                cout << "Remove what value?" << endl;
                getline(cin, key);
                table.remove(key);
                break;   
            }
            case seach:
            {
                cout << "Search what? " << endl;
                getline(cin, key);

                if (table.search(key))
                    cout << key << " found inside hash table." << endl;
                else
                    cout << key << " not found inside of hash table." << endl;
                break;
            }
            case display:
            {
                table.get_storage();               
                break;
            }
            case quit:
            {
                exit = true;
                table.~Hash_table();
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
