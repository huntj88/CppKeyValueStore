//
//  Node.cpp
//  KeyValueStore
//
//  Created by James Hunt on 4/14/19.
//  Copyright © 2019 James Hunt. All rights reserved.
//

#include <iostream>
#include "Node.hpp"

Node::Node(std::string key, std::string value) {
    this->key = key;
    this->value = value;
}

void Node::insert(Node ** rootNode, Node * newNode) {
    
    // replace as the root if less than first node
    if(newNode->key < this->key) {
        newNode->next = this;
        *rootNode = newNode;
        return;
    }
    
    // replace value of existing node with matching key
    if(newNode->key == this->key) {
        this->value = newNode->value;
        return;
    }
    
    // if a next node exists and the new node should fit between this node and the next
    if(next && newNode->key > this->key && newNode->key < next->key) {
        newNode->next = next;
        this->next = newNode;
    } else if(next) {
        // if next exists delegate the next node to handle insert
        next->insert(rootNode, newNode);
    } else {
        // if no next node, then set the new one as the next
        next = newNode;
    }
}

std::string * Node::find(std::string key) {
    if(this->key == key) {
        return &this->value;
    } else if(this->next) {
        return this->next->find(key);
    } else {
        return NULL;
    }
}

Node::~Node() {
    Node * next = this->next;
    delete next;
}
