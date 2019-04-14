//
//  main.cpp
//  KeyValueStore
//
//  Created by James Hunt on 4/14/19.
//  Copyright © 2019 James Hunt. All rights reserved.
//

#include <iostream>
#include "Store.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Store store;
    
    store.putVal("wowza", "supwow");
    store.putVal("sup", "sup");
    store.putVal("sup", "woow");
    store.putVal("wow", "supwow");
    store.putVal("sup1", "sup1");

    std::cout << store.getVal("sup1") << std::endl;
    return 0;
}

