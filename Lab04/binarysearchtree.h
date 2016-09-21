//
//  binarysearchtree.h
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#ifndef binarysearchtree_hpp
#define binarysearchtree_hpp

#include <stdio.h>
#include <string>

class Node {
public:
    std::string data_;
    Node* left_;
    Node* right_;

    Node(std::string);
};


class BinarySearchTree {
private:
    Node* root_;

    void InOrder(Node*);

public:
    BinarySearchTree();
    bool Insert(std::string);
    bool Search(std::string);
    void InOrder();
};



#endif /* binarysearchtree_h */
