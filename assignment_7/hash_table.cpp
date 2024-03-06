#include "hash_table.hpp"



Hash_table::Hash_table(int capacity)
{
    this->capacity = capacity;
    this->size = 0;

    this->storage = new string[this->capacity];
}

/* Hashes the value to determine where to place it in the hash table. */
int Hash_table::hash(string value)
{
    int key;
    for (char character : value)
    {
        key += (int)character;
    }
    return key % this->capacity;
}

bool Hash_table::add(string value)
{
    bool collsion = false;
    int bucket = hash(value);
    /* Places value in appropiate storage location */
    if (value == this->storage[bucket])
    {
        this->size -= 1;
        collsion = true;
    }
    this->size += 1;
    this->storage[bucket] = value;
    return collsion;
}

void Hash_table::search()
{
    
}















