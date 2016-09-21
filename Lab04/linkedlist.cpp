//
//  linkedlist.cpp
//
//  Created by Emma Steffens on 9/20/16.
//  Copyright © 2016 emmagrace. All rights reserved.
//

#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;

Node2::Node2(string data) {
    data_ = data;
    next_ = NULL;
}

LinkedList::LinkedList() {
    head_ = NULL;
    tail_ = NULL;
}

bool LinkedList::Insert(string data) {
    if (head_ == NULL) {
        // Empty list, make a head
        head_ = new Node2(data);
        tail_ = head_;
        return true;
    } else {
        // Non-empty list, use the tail to insert data
        Node2* curr = tail_;
        tail_ = new Node2(data);
        curr->next_ = tail_;
    }
    return false;
}

bool LinkedList::Search(string data) {
    Node2* curr = head_;
    while (curr != NULL) {
        if (curr->data_ == data) {
            return true;
        } else {
            curr = curr->next_;
        }
    }
    return false;
}

void LinkedList::Unnamed() {
    Node2* curr = head_;
    while (curr != NULL) {
        cout << curr->data_ << endl;
        curr = curr->next_;
    }
}
