#include <vector>
#include <iostream>
#include <algorithm>
#include "graph.hpp"
#include "edge.hpp"

using std::vector;
using std::make_pair;
using std::sort;
using std::cout;
using std:: endl;

Graph::Graph()
{
    this->size = 0;
}

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

/* Display all vertices inside of the graph */
void Graph::display_vertices()
{
    for (size_t i = 0; i < this->size; i++)
    {
        cout << endl << 
        "Name: "  << vertices[i]->name << endl << 
        "Value: " << vertices[i]->value << endl;
    }
    
}



/* Adds an edge with a specified weight connecting two given vertices */
void Graph::add_edge(string vertex_1, string vertex_2, int weight)
{
    /* Find the desired vertices. */
    Vertex* start = find_vertext(vertex_1);
    Vertex* end = find_vertext(vertex_2);

    /* If both verticves exist. */
    if(start != nullptr && end != nullptr && weight > 0 && edge_weight(vertex_1, vertex_2) == 0)
    {
        /* Make a new edge which connects both vertices. */
        Edge* edge = new Edge;
        edge->vertex_1 = start;
        edge->vertex_2 = end;
        edge->weight = weight;

        /* Put the edge's vertices into eachothers neighbors vector*/
        start->neighbors.push_back(end);
        end->neighbors.push_back(start);

        /* Add the edge */
        this->edges.push_back(edge);
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

/* Displays all edges inside of the graph */
void Graph::display_edges()
{
    for (size_t i = 0; i < this->edges.size(); i++)
    {
        cout << endl << 
        "Vertex 1: " << this->edges[i]->vertex_1->name << endl <<
        "Vertex 2: " << this->edges[i]->vertex_2->name << endl <<
        "Weight: "   << this->edges[i]->weight << endl;
    }
    
}

/* Uses Dijkstra's algorithm to return the shortest possible path between two vertices.*/
int Graph::shortest_path(string begining, string ending)
{
    /* Sets INFINITY to the largest possible int. */
    vector<int> distances(this->size, INFINITY);
    /* Keeps track of visited vertices. */
    vector<bool> searched(this->size, false);
    /* Queue to access vertices */
    vector<Vertex*> queue;

    int total_distance = 0; 

    Vertex* start = find_vertext(begining);

    for (size_t i = 0; i < this->size; i++)
    {
        if (this->vertices[i] == start)
        {
            distances[i] = 0;
        }
        queue.push_back(vertices[i]);
    }

    
    /* Find the vertex with the smallest distance */
    int smallest_index = nearest(distances, searched);
    while (queue[smallest_index]->name != ending || searched[smallest_index] != true)
    {
        smallest_index = nearest(distances, searched);
        total_distance += distances[smallest_index];

        /* For the number of vertex's neighbors */
        for (size_t i = 0; i < queue[smallest_index]->neighbors.size(); i++)
        {
            /* Check for neighbors */
            for (size_t j = 0; j < queue.size(); j++)
            {
                if (queue[smallest_index]->neighbors[i] == queue[j])
                {
                    int neighbor_dist = edge_weight(queue[smallest_index]->name, queue[j]->name);
                
                    distances[j] = neighbor_dist;
                }        
            }
        }
        searched[smallest_index] = true;
    }
    return total_distance;
}   

/* Helper function that returns the index of the closest vertex */
int Graph::nearest(vector<int>dist, vector<bool>searched)
{
    int smallest_dist = this->INFINITY; 
    int nearest= 0;

    for (size_t i = 0; i < this->size; i++)
    {
        if (searched[i] == false && dist[i] < smallest_dist)
        {
            smallest_dist = dist[i];
            nearest = i;
        }
    }
    return nearest;
}

/* Looks for an edge containing the two vertices provided and returns it's weight, returns 0 if edge does not exist*/
int Graph::edge_weight(string vertex_1, string vertex_2)
{
    Vertex* v1 = find_vertext(vertex_1);
    Vertex* v2 =  find_vertext(vertex_2);

    for (size_t i = 0; i < this->edges.size(); i++)
    {
        if ((edges[i]->vertex_1 == v1 && edges[i]->vertex_2 == v2) || (edges[i]->vertex_1 == v2 && edges[i]->vertex_2 == v1))
        {
            return edges[i]->weight;
        }
    }
    return 0;
}

/* Creates a Minimum Spanning Tree using Kruskal's algorithm */
void Graph::minimum_span_tree()
{
    vector<Vertex*> visited;
    vector<pair<int, Edge*>> edge_weights;

    /* Sets the edge_weights vector */
    for (size_t i = 0; i < this->edges.size(); i++)
    {
        edge_weights.push_back(make_pair(this->edges[i]->weight, this->edges[i]));
    }
    
    sort(edge_weights.begin(), edge_weights.end());
    
    Vertex* edge_vertex_1;
    Vertex* edge_vertex_2;
    while (visited.size() < this->size)
    {
        for (size_t i = 0; i < this->edges.size(); i++)
        {
            edge_vertex_1 = edge_weights[i].second->vertex_1;
            edge_vertex_2 = edge_weights[i].second->vertex_2;  

            if ((find(visited.begin(), visited.end(), edge_vertex_1) == visited.end()) || (find(visited.begin(), visited.end(), edge_vertex_2) == visited.end()))
            {
                if(find(visited.begin(), visited.end(), edge_vertex_1) == visited.end())
                    visited.push_back(edge_vertex_1);
                if(find(visited.begin(), visited.end(), edge_vertex_2) == visited.end())
                    visited.push_back(edge_vertex_2);

                cout << edge_vertex_1->name << "---" << edge_weights[i].first << "---" << edge_vertex_2->name << endl;  
            }
        }
    }
}
