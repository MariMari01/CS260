
#include <vector>
#include <algorithm>
#include "graph.hpp"
#include "edge.hpp"

using std::vector;
using std:: sort;

void Graph::add_vertex(string name, int value)
{
    /* Ensure a vertex with this name does not already exist */
    Vertex* new_vertex = find_vertext(name);

    if (new_vertex == nullptr)
    {
        /* Create new vertex */
        new_vertex = new Vertex;
        new_vertex->name = name;
        new_vertex->value = value;

        /* Add new vertex to graph's vector of vertices */
        this->vertices.push_back(new_vertex);
        this->size += 1;
    }
}

/* Adds an edge with a specified weight connecting two given vertices */
void Graph::add_edge(string vertex_1, string vertex_2, int weight)
{
    /* Find the desired vertices. */
    Vertex* start = find_vertext(vertex_1);
    Vertex* end = find_vertext(vertex_2);

    /* If both verticves exist. */
    if(start != nullptr && end != nullptr)
    {
        /* Make a new edge which connects both vertices. */
        Edge* edge = new Edge;
        edge->vertex_1 = start;
        edge->vertext_2 = end;
        edge->weight = weight;

        /* Put the edge inside of the neighbors vector for both edges */
        start->neighbrors.push_back(end);
        end->neighbrors.push_back(start);
    }
}

/* Finds a vertex inside of the graph's vertices vector using it's name */
Vertex* Graph::find_vertext(string vertex_name)
{
    for (size_t i = 0; i < this->size; i++)
    {
        if (vertices[i]->name == vertex_name)
        {
            return vertices[i];
        }
    }
    return nullptr;
}

/* Uses Dijkstra's algorithm to return the shortest possible path between two vertices.*/
int Graph::shortest_path(string begining, string ending)
{
    vector<int> distances;
    vector<Vertex*> previous;
    vector<Vertex*> queue;

    for (size_t i = 0; i < size; i++)
    {
        if(this->vertices[i]->name == begining)
        {
            distances.push_back(0);
        }
        else
            distances.push_back(1);
        previous.push_back(nullptr);

        queue.push_back(vertices[i]);
    }
    
    sort(queue.begin(), queue.end());
    while (!queue.empty())
    {
        Vertex* current = queue[0];
        queue.erase(queue.begin());

        for (size_t i = 0; i < current->neighbrors.size(); i++)
        {
            int path_length = 
        }
        
    }
    

}



