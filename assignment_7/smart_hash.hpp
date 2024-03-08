#pragma once
#include <string>

using std::string;

/* Hash_table class */
class Hash_table
{
    private:
        int size = 0;
        int capacity = 0;
        int hash(string value);
        int hash2(string value);
        string* storage = nullptr;

    public:
        Hash_table(int capacity);
        ~Hash_table();

        bool add(string value);
        void remove(string value);

        void get_storage();
        bool search(string value);
};
