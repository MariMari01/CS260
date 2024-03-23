
!![alt text](https://github.com/MariMari01/CS260/blob/main/final/design.png?raw=true)

1. Add Vertex function fulfilled on lines 19 - 35 inside file graph.cpp.
   This function has a time complexity of O(n) due to using the function "find_vertex" which
   iterates through the graphs n vertices.  

   ![alt text](https://github.com/MariMari01/CS260/blob/main/final/add_vertex.png?raw=true)

3. Add Edge function fulfilled on lines 52-74 inside file graph.cpp
   This function has a time complexity of O(n) due to using the function "find_vertex" which
   iterates through the graphs n vertices.  
   ![alt text](https://github.com/MariMari01/CS260/blob/main/final/add_edge.png?raw=true)

4. Shortest Path function fulfilled on lines 102-153 inside file graph.cpp
   Shortest Path has a time complexity of O(n^2) becuase of the nested for loop used to find
   the neighbors of a vertex.
   ![alt text](https://github.com/MariMari01/CS260/blob/main/final/shortest_path_1.png?raw=true)
   ![alt text](https://github.com/MariMari01/CS260/blob/main/final/shortest_path_2.png?raw=true)

6. Minimum Spanning Tree function fulfilled on lines 188-226 inside file graph.cpp
   MST function has a time complexity of O(n^2) because of the for loop nested inside of the while loop
   that checks until all edges are visted.
   ![alt text](https://github.com/MariMari01/CS260/blob/main/final/minimum_spanning_tree.png?raw=true)


Tests:
   1. ![alt text](https://github.com/MariMari01/CS260/blob/main/final/test_1.png?raw=true)
   2. ![alt text](https://github.com/MariMari01/CS260/blob/main/final/test_2.png?raw=true)
   3. ![alt text](https://github.com/MariMari01/CS260/blob/main/final/test_3.png?raw=true)
   4. ![alt text](https://github.com/MariMari01/CS260/blob/main/final/test_4.png?raw=true)
   5. ![alt text](https://github.com/MariMari01/CS260/blob/main/final/test_5.png?raw=true)
