//
//  graph.cpp
//  graph2
//
//  Created by Christian Joachim and Emma Steffens on 10/4/16.
//  Copyright © 2016 Christian Joachim, Emma Steffens. All rights reserved.
//

#include "graph.hpp"
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

Node::Node(string data) {
    data_ = data;
}

Graph::Graph() {

}

void Graph::AddVertex(string data) {
    Node* n = new Node(data);
    node_list_.push_back(n);
}

Node* Graph::Search(string data) {
    for (int i = 0; i < node_list_.size(); i++) {
        if (data == node_list_[i]->data_) {
            return node_list_[i];
        }
    }
    return NULL;
}

void Graph::AddEdge(string data1,string data2, float weight) {
    Node* address1 = Search(data1);
    Node* address2 = Search(data2);

    if (address1 != NULL && address2!= NULL) {
        address1->edge_list_.push_back(address2);
        address2->edge_list_.push_back(address1);
        address1->weight_list_.push_back(weight);
        address2->weight_list_.push_back(weight);
    }
}

void Graph::ToGraphviz() {
    ofstream outfile;
    outfile.open ("DotFile.dot");

    if (outfile) {
        outfile << "digraph G {" << endl << "node [shape = circle];" << endl
            << "node [color = blue];" << endl;
        for (int i = 0; i<node_list_.size(); i++) {
            if (node_list_[i]->edge_list_.size() == 0) {                        // single node no edge
                outfile << node_list_[i]->data_ << ";" << endl;
            } else {
                for (int j = 0; j<node_list_[i]->edge_list_.size(); j++) {     // access all the elemets in EL
                    // accessing all data of elements.
                    outfile << node_list_[i]->data_ << " -> " << node_list_[i]->edge_list_[j]->data_;
                    if (node_list_[i]->weight_list_[j] != 0)
                    {
                        outfile << "[ label = " << node_list_[i]->weight_list_[j] << " ]";
                    }

                outfile<< ";" << endl;
                }
            }
        }
        outfile << "}" << endl;
    } else {
        cout << "File not found." << endl;
    }
    outfile.close();
}

/*Graph Graph::PrimMST() {
    Graph MST;
    Node* to_add;
    queue<Node*> all_nodes;

    for (short i = 0; i < this->node_list_; i++) {
        all_nodes.push(this->node_list_[i]);
    }

    MST.AddVertex(all_nodes.front());
    all_nodes.pop();
    while (!all_nodes.empty()) {
        for (short i = 0

    }

    return MST;
}*/









