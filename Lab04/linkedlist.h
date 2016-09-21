//
//  linkedlist.h
//
//  Created by Emma Steffens on 9/20/16.
//  Copyright © 2016 emmagrace. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <stdio.h>
#include <string>

class Node2 {
public:
    std::string data_;
    Node2* next_;

public:
    Node2(std::string);
};


class LinkedList {
    Node2* head_;
    Node2* tail_;

public:
    LinkedList();
    bool Insert(std::string);
    bool Search(std::string);
    void Unnamed();
};

#endif /* linkedlist_h */
