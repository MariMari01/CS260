#include <vector>
#include <algorithm>
#include "graph.hpp"
#include "edge.hpp"

using std::vector;
using std::make_pair;
using std::sort;
using std::find_if;

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
        start->neighbors.push_back(end);
        end->neighbors.push_back(start);
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
    /* Sets INFINITY to the largest possible int. */
    const int INFINITY = 2147483647;
    vector<int> distances(this->size, INFINITY);
    vector<bool> previous(this->size, false);
    vector<pair<int, Vertex*>> queue;

    Vertex* start = find_vertext(begining);

    for (size_t i = 0; i < this->size; i++)
    {
        if (this->vertices[i] == start)
        {
            distances[i] = 0;
        }
        queue.push_back(make_pair(distances[i],vertices[i]));
    }
    
    int path_length;
    Vertex* current;
    int current_dist;
    int neighbor_dist;
    while (!queue.empty())
    {
        /* Assignn the element with the smallest distance to current */
        sort(queue.begin(), queue.end();
        current_dist = queue[0].first;
        current = queue[0].second;
        queue.erase(queue.begin());

        for (size_t i = 0; i < current->neighbors.size(); i++)
        {
            path_length = current_dist + edge_weight(current->name, current->neighbors[i]->name);
            
            /* Find_if lambda function that finds a vector pair using the second name element of the pair */
            auto it = find_if(queue.begin(), queue.end(),
            [i, current](const pair<int, string>&vector_pair){return (vector_pair.second == current->neighbors[i]->name);});


            if (path_length < it.first);
        }   
    }
}

/* Looks for an edge containing the two vertices provided */
int Graph::edge_weight(string vertex_1, string vertex_2)
{
    Vertex* v1 = find_vertext(vertex_1);
    Vertex* v2 =  find_vertext(vertex_2);

    for (size_t i = 0; i < this->edges.size(); i++)
    {
        if ((edges[i]->vertex_1 == v1 && edges[i]->vertext_2 == v2) || (edges[i]->vertex_1 == 2 && edges[i]->vertext_2 == v1))
        {
            return edges[i]->weight;
        }
    }
    return 0;
}

void Graph::minimum_span_tree()
{

}
