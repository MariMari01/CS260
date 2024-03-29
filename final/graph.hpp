#pragma once
#include <vector>
#include <string>
#include "vertex.hpp"
#include "edge.hpp"

using std::vector;
using std::pair;
using std::string;

class Graph
{
    private:
        int size;
        vector<Vertex*> vertices;
        vector<Edge*> edges;
    public:
        Graph();
        ~Graph();
        const int INFINITY = 2147483647;

        void add_vertex(string name, int value);
        
        void add_edge(string vertex_1, string vertex_2, int weight);
        Vertex* find_vertext(string vertex_name);
        void display_vertices();

        int shortest_path(string begining, string ending);
        int nearest(vector<int> dist, vector<bool>searched);
        int edge_weight(string vertex_1, string vertex_2);
        void display_edges();

        void minimum_span_tree();

};


