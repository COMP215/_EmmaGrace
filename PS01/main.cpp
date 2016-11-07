//
//  main.cpp
//  lab05
// Worked together with Emma.


#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    // bipartite
    Graph G;
    G.AddVertex("Hello");
    G.AddVertex("there");
    G.AddVertex("friend");
    G.AddEdge(3, "Hello", "there");
    G.AddEdge(13, "there", "friend");
    cout << G.IsBipartite() << endl;
    
    // bipartite
    Graph H;
    H.AddVertex("1");
    H.AddVertex("2");
    H.AddVertex("3");
    H.AddVertex("4");
    H.AddEdge(4, "1", "2");
    H.AddEdge(10, "2", "4");
    H.AddEdge(2.5, "4", "3");
    H.AddEdge(.6, "3", "1");
    cout << H.IsBipartite() << endl;
    
    // not bipartite
    Graph I;
    I.AddVertex("1");
    I.AddVertex("2");
    I.AddVertex("3");
    I.AddVertex("4");
    I.AddVertex("5");
    I.AddEdge(4.0, "1", "4");
    I.AddEdge(66, "4", "2");
    I.AddEdge(1.05, "4", "5");
    I.AddEdge(.99, "5", "2");
    I.AddEdge(.3, "5", "3");
    cout << I.IsBipartite() << endl;
    
    // bipartite
    Graph J;
    J.AddVertex("A");
    cout << J.IsBipartite() << endl;
    
    // bipartite
    Graph K;
    K.AddVertex("A");
    K.AddVertex("B");
    K.AddVertex("C");
    K.AddVertex("D");
    K.AddEdge(.7, "A", "B");
    K.AddEdge(3, "B", "C");
    cout << K.IsBipartite() << endl;
    
    K.ToGraphViz();
    
    // not bipartite
    Graph L;
    L.AddVertex("A");
    L.AddVertex("B");
    L.AddVertex("C");
    L.AddEdge(.4, "A", "B");
    L.AddEdge(1, "B", "C");
    L.AddEdge(5, "A", "C");
    cout << L.IsBipartite() << endl << endl;
    
    L.ToGraphViz();
    
    G = L.PrimMST();
    G.ToGraphViz();
    
    //L.Dijkstra();
    
    return 0;
}
