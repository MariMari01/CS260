#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

struct Vertex
{
    string name;
    int value;
    vector<Vertex*> neighbrors; 
};

