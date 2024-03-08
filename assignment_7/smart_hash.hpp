#pragma once
#include <string>

using std::string;

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

        bool search(string value);
};

Hash_table::Hash_table(int capacity)
{
    this->capacity = capacity;
    this->size = 0;

    this->storage = new string[this->capacity];
}
