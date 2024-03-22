#include <iostream>
#include "graph.hpp"
using std::cout;
using std:: endl;
/* 
File: main.cpp
Author: Sam Garcia Lopez
Date: 21.3.2004

This file tests the functions of graph.cpp which represents a graph,
this graph has methods to:

Add vertices

Add Edges

Return a shortest path between two vertices by using Dijkstra's algorithm

Return a Minimum Spanning Tree by using Kruskal's algorithm
*/

int main()
{
    Graph graph; 

    /* Add Vertex tests */
    cout << endl << 
    "--- ADD VERTEX TESTS ---" << endl <<
    "Adding new vertices" << endl;
    graph.add_vertex("A", 2);
    graph.add_vertex("B", 78);
    graph.add_vertex("C", 42);
    graph.add_vertex("D", 21);
    graph.display_vertices();

    cout << endl << 
    "Attempting to add a vertex with a name already in use" << endl
    << "Expected result: Nothing happening" << endl;

    graph.add_vertex("A", 9);
    graph.display_vertices();


    /* Add Edges tests */
    cout << endl << 
    "--- ADD EDGES TESTS ---" << endl <<
    "Adding new edges" << endl;

    graph.add_edge("A","B", 5);
    graph.add_edge("A","C", 10);
    graph.add_edge("B", "C", 90);
    graph.add_edge("B", "D", 2);
    graph.add_edge("D", "A", 1);
    graph.display_edges();

    cout << endl << 
    "Adding edge that already exists" << endl <<
    "Expected result: nothing happening" << endl;

    graph.add_edge("B", "A", 60);

    graph.display_edges();

    /* Shortes Path tests */

    /* Minimum Spanning Tree tests */
    cout << endl << 
    "--- MINIMUM SPANNING TREE ---" << endl;

    graph.minimum_span_tree();
}
