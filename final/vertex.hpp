
#include <vector>
#include "edge.hpp"
using std::vector;

struct Vertex
{
    int value;
    vector<Edge*> neighbrors; 
};
