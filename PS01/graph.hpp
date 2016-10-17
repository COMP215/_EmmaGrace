//
//  graph.hpp
//  graph2
//
//  Created by Christian Joachim and Emma Steffens on 10/4/16.
//  Copyright © 2016 Christian Joachim, Emma Steffens. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp
#include <iostream>
#include <vector>

class Node {
public:
    std::string data_;
    Node(std::string);
    std::vector<Node*> edge_list_;
    std::vector<float> weight_list_;

};

class Graph {
public:
    Graph();
    void AddVertex(std::string);
    void AddEdge(std::string, std::string, float);
    void ToGraphviz();
    Graph PrimMST();

private:
    std::vector<Node*> node_list_;
    Node* Search(std::string);
};



#endif /* graph_hpp */
