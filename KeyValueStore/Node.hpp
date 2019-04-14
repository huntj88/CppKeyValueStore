//
//  Node.hpp
//  KeyValueStore
//
//  Created by James Hunt on 4/14/19.
//  Copyright © 2019 James Hunt. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>

class Node {
public:
    Node(std::string key, std::string value);
    ~Node();
    
    void insert(Node ** rootNode, Node * newNode);
    std::string * find(std::string key);
    
private:
    Node * next;
    std::string key;
    std::string value;
};



#endif /* Node_hpp */
