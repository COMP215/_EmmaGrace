//
//  main.cpp
//  graph2
//
//  Created by Christian Joachim and Emma Steffens on 10/4/16.
//  Copyright © 2016 Christian Joachim, Emma Steffens. All rights reserved.
//

#include <iostream>
#include "graph.hpp"

int main() {

    Graph G;
    G.AddVertex("hi");
    G.AddVertex("chris");
    G.AddEdge("hi", "chris", 0);
    G.AddVertex("this");
    G.AddVertex("is");
    G.AddVertex("a");
    G.AddVertex("test");
    G.AddEdge("this", "is", 5);
    G.AddEdge("is", "a", .66);
    G.AddEdge("a", "test", .02);
    G.AddVertex("success!");
    G.AddEdge("this", "test", 1.58);
    G.AddEdge("test", "is", 0);
    G.AddEdge("a", "success!", 20);
    G.AddVertex("loner");
    G.AddEdge("fail", "test", 6.9);

    G.ToGraphviz();
    G.PrimMST();







    return 0;
}
