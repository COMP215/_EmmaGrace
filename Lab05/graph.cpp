#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
#include "graph.h"
using namespace std;

Node3::Node3(string data) {
    data_ = data;
}

Graph::Graph() {

}

Node3* Graph::FindNode(string data) {
    int vect_size = list_nodes_.size();

    // if the string we're looking for is encased in a node, return its location
    for (short i = 0; i < vect_size; i++) {
        if (data == list_nodes_[i]->data_) {
            return list_nodes_[i];
        }
    }
    // didn't find it -- return null pointer
    return NULL;
}

bool Graph::AddVertex(string data) {
    // vertex does not already exist -- add it and say we did (return true)
    if (FindNode(data) == NULL) {
        list_nodes_.push_back(new Node3(data));
        return true;
    }
    // vertex already existed -- do not add it again
    return false;
}


bool Graph::AddEdge(string a, string b) {
    Node3* loc_a = FindNode(a);
    Node3* loc_b = FindNode(b);

    // if the vertices exist, connect them and say we did (return true)
    if (loc_a != NULL && loc_b != NULL) {
        edge_list_.push_back(tuple<Node3*, Node3*>(loc_a, loc_b));
        edge_list_.push_back(tuple<Node3*, Node3*>(loc_b, loc_a));
        return true;
    }
    // one or both do not exist -- failed to connect them
    return false;
}

bool Graph::IsBipartite() {
    int vect_size = edge_list_.size();

    // two arbitrary lists we will divide our vertices between
    vector<string> list1;
    vector<string> list2;

    // cycling through each tuple in the edge list
    for (short i = 0; i < vect_size; i++) {
        string str0, str1;

        // the strings contained within the current tuple -- (str0, str1)
        str0 = get<0>(edge_list_[i])->data_;
        str1 = get<1>(edge_list_[i])->data_;

        // unpleasant intermediate variables
        vector<string>::iterator temp1 = find(list1.begin(), list1.end(), str0);
        vector<string>::iterator temp2 = find(list2.begin(), list2.end(), str0);
        vector<string>::iterator temp3 = find(list1.begin(), list1.end(), str1);
        vector<string>::iterator temp4 = find(list2.begin(), list2.end(), str1);

        // the intermediates above, converted into nice booleans
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
            // either str1 is in list2 or it is not found either -- put str0 in list1
            } else {
                list1.push_back(str0);
                str0_in_list1 = true;
            }
        // str0 found
        } else {
            // str0 is in list1
            if (str0_in_list1) {
                // they are both in list1 -- not bipartite
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
                // they are both in list2 -- not bipartite
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
    // all pairs sorted without fail -- is bipartite
    return true;
}
