//
//  Store.cpp
//  KeyValueStore
//
//  Created by James Hunt on 4/14/19.
//  Copyright © 2019 James Hunt. All rights reserved.
//

#include "Store.hpp"

std::string Store::getVal(std::string key) {
    return *(rootNode->get(key));
};

void Store::putVal(std::string key, std::string value) {
    Node * newNode = new Node(key, value);
    
    if(rootNode) {
        rootNode->insert(&rootNode, newNode);
    } else {
        rootNode = newNode;
    }
}

Store::~Store() {
    delete rootNode;
}
