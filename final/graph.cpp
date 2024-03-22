#include <vector>
#include <algorithm>
#include "graph.hpp"
#include "edge.hpp"

using std::vector;
using std::make_pair;
using std::sort;
using std::find_if;

/* Add a vertex to the graph */
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
    if(start != nullptr && end != nullptr && weight > 0)
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
    vector<int> distances(this->size, INFINITY);
    vector<bool> searched(this->size, false);
    vector<pair<int, bool>> queue;

    Vertex* start = find_vertext(begining);

    for (size_t i = 0; i < this->size; i++)
    {
        if (this->vertices[i] == start)
        {
            distances[i] = 0;
        }
        queue.push_back(make_pair(distances[i],searched[i]));
    }
    
    int path_length;
    int nearest_index;

    while (!queue.empty())
    {
        nearest_index = nearest(distances, searched);
        auto current = queue[nearest_index];
        Vertex* current_vertex = vertices[nearest_index];

        queue.erase(queue.begin() + nearest_index);

        for (size_t i = 0; i < this->size i++)
        {
            /* Ensure that the current edge is a neighbor */
            if ((edge_weight(current_vertex->name, this->vertices[i]->name) != 0) && (searched[i] == false))
            {
                Vertex* current_neighbor = this->vertices[i];

                int neighbor_distance = edge_weight(current_vertex->name, current_neighbor->name);

                path_length = current.first + neighbor_distance;

                if (path_length < distances[i])
                {
                    distances[i] = path_length;
                    searched[i] = true;
                }
                if (vertices[i]->name == ending)
                {
                    return distances[i];
                }
            }
        }   
    }
}

/* Helper function that returns the index of the closest vertex */
int Graph::nearest(vector<int>dist, vector<bool>searched)
{
    int smallest_dist = this->INFINITY; 
    int nearest= 0;

    for (size_t i = 0; i < this->size; i++)
    {
        if (searched[i] == false && dist[i] < smallest_dist)
            smallest_dist = dist[i];
            nearest = i;
    }
    return nearest;
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
