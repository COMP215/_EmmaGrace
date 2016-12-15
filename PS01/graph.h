//
//  graph.h
//  lab05
//
//  Created by Christian Joachim on 10/3/16.
//  Copyright © 2016 Christian Joachim. All rights reserved.
//

#ifndef ECGRAPH_H
#define ECGRAPH_H

#include <tuple>
#include <vector>
#include <string>

// It's named this so I could use it with a linked list or binary search tree without conflict -- Emma
class Node3 {
    public:
        Node3(std::string);
        
        std::string data_;
        float path_cost_;
    };

class Graph {
    private:
        Node3* FindNode(std::string);
        std::vector<std::tuple<float, Node3*, Node3*>> FindEdgesTo(std::string);
        std::vector<std::tuple<float, Node3*, Node3*>> FindEdgesFrom(std::string);
        bool AddVertex(Node3*);
        bool AddEdge(std::tuple<float, Node3*, Node3*>);
        bool ReverseAddEdge(std::tuple<float, Node3*, Node3*>);
        
        std::vector<Node3*> node_list_;
        std::vector<std::tuple<float, Node3*, Node3*>> edge_list_;

    public:
        Graph();
        bool AddVertex(std::string);
        bool AddEdge(float, std::string, std::string);
        bool IsBipartite();
        void ToGraphViz();
        Graph PrimMST();
        Graph KruskalMST();
};

bool BetterEdge(std::tuple<float, Node3*, Node3*>, std::tuple<float, Node3*, Node3*>);

#endif // ECGRAPH_H
