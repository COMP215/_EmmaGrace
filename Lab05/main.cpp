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
    G.AddEdge("Hello", "there");
    G.AddEdge("there", "friend");
    cout << G.IsBipartite() << endl;

    // bipartite
    Graph H;
    H.AddVertex("1");
    H.AddVertex("2");
    H.AddVertex("3");
    H.AddVertex("4");
    H.AddEdge("1", "2");
    H.AddEdge("2", "4");
    H.AddEdge("4", "3");
    H.AddEdge("3", "1");
    cout << H.IsBipartite() << endl;

    // not bipartite
    Graph I;
    I.AddVertex("1");
    I.AddVertex("2");
    I.AddVertex("3");
    I.AddVertex("4");
    I.AddVertex("5");
    I.AddEdge("1", "4");
    I.AddEdge("4", "2");
    I.AddEdge("4", "5");
    I.AddEdge("5", "2");
    I.AddEdge("5", "3");
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
    K.AddEdge("A", "B");
    K.AddEdge("B", "C");
    cout << K.IsBipartite() << endl;

    // not bipartite
    Graph L;
    L.AddVertex("A");
    L.AddVertex("B");
    L.AddVertex("C");
    L.AddEdge("A", "B");
    L.AddEdge("B", "C");
    L.AddEdge("A", "C");
    cout << L.IsBipartite() << endl;

    return 0;
}
