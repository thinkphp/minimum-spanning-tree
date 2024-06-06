#  Minimum Spanning Tree
 
   Given a connected, undirected graph, a spanning tree of that graph is subgraph that is tree and connects all the vertices together.
   A single graph can have many different spanning trees. We can also assign a weight to each edge, which is a number representing
   how unfavorable it is, and use this to assign a weight to a spanning tree by computing the sum of the weights of the edges in that spanning tree.
   A Minimum Spanning Tree (MST) or minimum weight spanning tree is then a spanning tree with weight less than or equal to the weight or
   every other spanning tree. More generally, any undirected graph (not necessarily connected) has a minimum spanning forest, which is union
    of minimum spanning trees for its connected components.

### Kruskal's Algorithm

   The Kruskal Algorithm starts with a FOREST which consists of n trees. Each and everyone tree, consists only by one node
   and nothink else. In every step of the algorithm, two different trees of this forest are connected to a bigger tree. Therefore
   we keep having less and bigger trees in our forest until we end up in a tree which is the minimum spanning tree. In every step we
   choose the side with the least cost, which means that we are still under GREEDY policy. IF the chosen sied connects nodes which 
   belong in the same tree the side is rejected, and not examined again because it could produce a circle which will destroy our tree.
   Either this side or the next one in of least cost will connect nodes of different trees, and this we insert connecting two small trees
   into a bigger one. 

### Prime's Algorithm


### Problem Set

https://www.infoarena.ro/problema/apm

## References

   http://en.wikipedia.org/wiki/Minimum_spanning_tree  
   https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
 
 

