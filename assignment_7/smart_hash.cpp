#include "smart_hash.hpp"


/* Hash Table Constructor. */
Hash_table::Hash_table(int capacity)
{
    this->capacity = capacity;
    this->size = 0;

    this->storage = new string[this->capacity];
}

/* Hashes the key to determine where to place it in the hash table. */
int Hash_table::hash(string key)
{
    int value;
    for (char character : key)
    {
        value += (int)character;
    }
    return value;
}
/* Second hash function */
int Hash_table::hash2(string key)
{
    int char_num;
    for (char character : key)
    {
        char_num += 1; 
    }
    return char_num;
}

/* Adds the key to the hash table's storage */
bool Hash_table::add(string key)
{
    bool collsion = false;
    int bucket = (hash(key) + hash2(key) % this->capacity);
    /* Places key in appropiate storage location */
    if (this->storage[bucket] == key)
    {
        this->size -= 1;
        collsion = true;
    }
    this->size += 1;
    this->storage[bucket] = key;
    return collsion;
}
/* Removes the  */
void Hash_table::remove(string key)
{
    int key_pos = (hash(key) + hash2(key)) % this->capacity;
    if (this->storage[key_pos] == key)
    {
        this->storage[key_pos] = "";
    }
}

/* Searches if a key exists inside of the Hashtable. */
bool Hash_table::search(string key)
{
    bool is_present = false;
    int bucket = (hash(key) + hash2(key)) % this->capacity;
    if (this->storage[hash(key)] == key)
    {
        is_present = true;
    }
    return is_present;        
}
