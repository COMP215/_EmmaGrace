#ifndef ECGRAPH_H
#define ECGRAPH_H

#include <tuple>
#include <vector>
#include <string>

// it's named this so I could use it with a linked list or binary search tree without conflict -- Emma
class Node3 {
public:
    Node3(std::string);

    std::string data_;
};

class Graph {
public:
    Graph();
    bool AddVertex(std::string);
    bool AddEdge(std::string, std::string);
    bool IsBipartite();

private:
    Node3* FindNode(std::string);

    std::vector<Node3*> list_nodes_;
    std::vector<std::tuple<Node3*, Node3*>> edge_list_;
};

#endif // ECGRAPH_H
