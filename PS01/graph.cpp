//
//  graph.cpp
//  lab05
//
//  Created by Christian Joachim on 10/3/16.
//  Copyright © 2016 Christian Joachim. All rights reserved.
//

#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <fstream>
#include "graph.h"
using namespace std;

// --Node stuff--

Node3::Node3(string data) {
    data_ = data;
    path_cost_ = 1000000;
}

// --Graph stuff--

Graph::Graph() {
    // CTOR that does nothing because otherwise g++ yells at me
}

// -Private-

Node3* Graph::FindNode(string data) {
    int vect_size = node_list_.size();
    
    // if the string we're looking for is encased in a node, return its location
    for (short i = 0; i < vect_size; i++) {
        if (data == node_list_[i]->data_) {
            return node_list_[i];
        }
    }
    // didn't find it -- return null pointer
    return NULL;
}

vector<tuple<float, Node3*, Node3*>> Graph::FindEdgesTo(string target) {
    vector<tuple<float, Node3*, Node3*>> target_incidents;
    
    // If the 1th element in the tuple is the target, add it to the incidents
    for (short i = 0; i < edge_list_.size(); i++) {
        if (get<1>(edge_list_[i])->data_ == target) {
            target_incidents.push_back(edge_list_[i]);
        }
    }
    
    return target_incidents;
}

vector<tuple<float, Node3*, Node3*>> Graph::FindEdgesFrom(string target) {
    // For comments see FindEdgesTo(string target)
    vector<tuple<float, Node3*, Node3*>> target_incidents;
    
    for (short i = 0; i < edge_list_.size(); i++) {
        if (get<2>(edge_list_[i])->data_ == target) {
            target_incidents.push_back(edge_list_[i]);
        }
    }
    
    return target_incidents;
}

bool Graph::AddVertex(Node3* node) {
    // For comments see AddVertex(string data)
    if (FindNode(node->data_) == NULL) {
        node_list_.push_back(node);
        return true;
    }
    return false;
}

bool Graph::AddEdge(std::tuple<float, Node3*, Node3*> edge) {   
    // For comments see AddEdge(float weight, string a, string b)
    Node3* loc1 = FindNode(get<1>(edge)->data_);
    Node3* loc2 = FindNode(get<2>(edge)->data_);
    
    if (loc1 != NULL && loc2 != NULL) {
        edge_list_.push_back(edge);
        return true;
    }
    return false;
}

bool Graph::ReverseAddEdge(std::tuple<float, Node3*, Node3*> edge) {   
    // For comments see AddEdge(float weight, string a, string b)
    Node3* loc1 = FindNode(get<1>(edge)->data_);
    Node3* loc2 = FindNode(get<2>(edge)->data_);
    
    if (loc1 != NULL && loc2 != NULL) {
        edge_list_.push_back(tuple<float, Node3*, Node3*>(get<0>(edge), loc2, loc1));
        return true;
    }
    return false;
}

// -Public-

bool Graph::AddVertex(string data) {
    // Vertex does not already exist -- add it and say we did (return true)
    if (FindNode(data) == NULL) {
        node_list_.push_back(new Node3(data));
        return true;
    }
    // Vertex already existed -- do not add it again
    return false;
}

bool Graph::AddEdge(float weight, string a, string b) {
    Node3* loc_a = FindNode(a);
    Node3* loc_b = FindNode(b);
    
    // If the vertices exist, connect them and say we did (return true)
    if (loc_a != NULL && loc_b != NULL) {
        edge_list_.push_back(tuple<float, Node3*, Node3*>(weight, loc_a, loc_b));
        edge_list_.push_back(tuple<float, Node3*, Node3*>(weight, loc_b, loc_a));
        
        return true;
    }
    // One or both do not exist -- failed to connect them
    return false;
}

bool Graph::IsBipartite() {
    int vect_size = edge_list_.size();
    
    // Two arbitrary lists we will divide our vertices between
    vector<string> list1;
    vector<string> list2;
    
    // Cycling through each tuple in the edge list
    for (short i = 0; i < vect_size; i++) {
        string str0, str1;
        
        // The strings contained within the current tuple -- (weight, str0, str1)
        str0 = get<1>(edge_list_[i])->data_;
        str1 = get<2>(edge_list_[i])->data_;
        
        // Unpleasant intermediate variables
        vector<string>::iterator temp1 = find(list1.begin(), list1.end(), str0);
        vector<string>::iterator temp2 = find(list2.begin(), list2.end(), str0);
        vector<string>::iterator temp3 = find(list1.begin(), list1.end(), str1);
        vector<string>::iterator temp4 = find(list2.begin(), list2.end(), str1);
        
        // The intermediates above, converted into nice booleans
        bool str0_in_list1 = !(temp1 == list1.end());
        bool str0_in_list2 = !(temp2 == list2.end());
        bool str1_in_list1 = !(temp3 == list1.end());
        bool str1_in_list2 = !(temp4 == list2.end());
        
        // str0 not found
        if (!str0_in_list1 && !str0_in_list2) {
            // str1 is in list1 -- put str0 in list2
            if (str1_in_list1) {
                list2.push_back(str0);
                str0_in_list2 = true;
                // Either str1 is in list2 or it is not found either -- put str0 in list1
            } else {
                list1.push_back(str0);
                str0_in_list1 = true;
            }
            // str0 found
        } else {
            // str0 is in list1
            if (str0_in_list1) {
                // They are both in list1 -- not bipartite
                if (str1_in_list1) {
                    return false;
                }
                // str1 is not found -- put into list2
                else if (!str1_in_list2) {
                    list2.push_back(str1);
                    str1_in_list2 = true;
                }
                // str1 is already in list2 -- do nothing
                // str0 is in list2
            } else {
                // They are both in list2 -- not bipartite
                if (str1_in_list2) {
                    return false;
                    // str1 is not found -- put into list1
                } else if (!str1_in_list1) {
                    list1.push_back(str1);
                    str1_in_list1 = true;
                }
                // str1 is already in list1 -- do nothing
            }
        }
    }
    // All pairs sorted without fail -- is bipartite
    return true;
}

void Graph::ToGraphViz() {
    // This is a lazy filename scheme
    static short counter = 0;
    string filenums[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    
    ofstream outfile;
    outfile.open ("DotFile" + filenums[counter] + ".dot");
    counter++;

    if (outfile) {
        // Formatting junk
        outfile << "digraph G {" << endl << "node [shape = circle];" << endl
            << "node [color = blue];" << endl;
        for (short i = 0; i < node_list_.size(); i++) {    // Cycling through nodes in graph
            vector<tuple<float, Node3*, Node3*>> edges_from = FindEdgesFrom(node_list_[i]->data_); 
            vector<tuple<float, Node3*, Node3*>> edges_to = FindEdgesTo(node_list_[i]->data_);           
            if (edges_to.size() == 0 && edges_from.size() == 0) {    // Node has no edges                       
                outfile << node_list_[i]->data_ << ";" << endl;
            } else {    // Node has edges
                for (short j = 0; j < edges_from.size(); j++) {    // Print only the edges from each node, to avoid double counting
                    outfile << get<1>(edges_from[j])->data_ << " -> " << get<2>(edges_from[j])->data_;
                    if (get<0>(edges_from[j]) != 0) {    // Weighted edges get extra text
                        outfile << "[ label = " << get<0>(edges_from[j]) << " ]";
                    }
                    outfile << ";" << endl;
                }
            }
        }
        outfile << "}" << endl;
    } else {
        cout << "File not found." << endl;
    }
    outfile.close();
}

Graph Graph::PrimMST() {
    // Assumes undirected graph with no unconnected vertices
    
    deque<string> open, closed;
    vector<tuple<float, Node3*, Node3*>> temp, candidates;
    Graph G;
    
    // Adding first vertex to tree and closed list
    closed.push_back(node_list_[0]->data_);
    G.AddVertex(node_list_[0]);    
    // Creating open list
    for (short i = 1; i < node_list_.size(); i++) {
        open.push_back(node_list_[i]->data_);
    }
    
    while (!open.empty()) {    // While open vertices
        for (short i = 0; i < closed.size(); i++) {    // Find all edges that connect to the existing tree
            temp = FindEdgesTo(closed[i]);            
            for (short j = 0; j < temp.size(); j++) {
                if (find(open.begin(), open.end(), get<2>(temp[j])->data_) != open.end()) {    // If an edge connects to an open vertex, add it to candidate edges
                    candidates.push_back(temp[j]);
                }
            }
        }        
        sort(candidates.begin(), candidates.end(), BetterEdge);    // The lowest cost candidate is now first
        // Add first candidate to tree
        G.AddVertex(get<2>(candidates[0]));
        G.AddEdge(candidates[0]);
        G.ReverseAddEdge(candidates[0]);
        // Move newly connected vertex from open to closed
        closed.push_back(get<2>(candidates[0])->data_);
        open.erase(find(open.begin(), open.end(), get<2>(candidates[0])->data_));
        // Don't forget to clear the vectors! They aren't overwritten like an array would be
        candidates.clear();
        temp.clear();
    }    
    return G;
}

Graph Graph::KruskalMST() {
    vector<tuple<float, Node3*, Node3*>> all_edges = edge_list_;
    vector<vector<string>> tree_nodes;
    short i = 0;
    short loc_1, loc_2;
    short added = 0;
    Graph G;
    
    // Because vectors don't have a pop front, we use descending order
    sort(all_edges.begin(), all_edges.end(), BetterEdge);
    reverse(all_edges.begin(), all_edges.end());
    while (added < node_list_.size() && tree_nodes.size() != 1) {
        loc_1 = -1;
        loc_2 = -1;
        vector<string> temp;
        // Does it form a loop?
        for (short j = 0; j < tree_nodes.size(); j++) {
            for (short k = 0; k < tree_nodes[j].size(); k++) {
                // Which subtree does each of the edge's nodes belong to?
                if (get<1>(all_edges[i])->data_ == tree_nodes[j][k]) {
                    loc_1 = j;
                }
                if (get<2>(all_edges[i])->data_ == tree_nodes[j][k]) {
                    loc_2 = j;
                }
            }
        }
        if (loc_1 == -1) {
            // Neither node in a tree
            if (loc_2 == -1) {
                // add to graph
                temp.push_back(get<1>(all_edges[i])->data_);
                temp.push_back(get<2>(all_edges[i])->data_);
                tree_nodes.push_back(temp);
                added += 2;
            // Only the second node is in a tree -- add the first to that tree
            } else {
                // add to graph
                tree_nodes[loc_2].push_back(get<1>(all_edges[i])->data_);
                added++;
            }
        // Only the first node is in a tree -- add the second to that tree
        } else if (loc_2 == -1) {
            // add to graph
            tree_nodes[loc_1].push_back(get<2>(all_edges[i])->data_);
            added++;
        // They are both in separate trees -- merge them
        } else if (loc_2 != loc_1) {
            // add to graph
            while (!tree_nodes[loc_2].empty()) {
                tree_nodes[loc_1].push_back(tree_nodes[loc_2].back());
                tree_nodes[loc_2].pop_back();
            }
            tree_nodes[loc_2].erase();
        }
        // else they are in the same tree = loop -- do nothing
        i++;
    }
    return G;
}

// --Extra--

bool BetterEdge(tuple<float, Node3*, Node3*> edge1, tuple<float, Node3*, Node3*> edge2) {
    return (get<0>(edge1) < get<0>(edge2));
}
