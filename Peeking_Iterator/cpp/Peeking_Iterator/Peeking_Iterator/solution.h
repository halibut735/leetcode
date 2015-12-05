//
//  solution.h
//  Peeking_Iterator
//
//  Created by 中央政治局常委 on 15/10/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        next();
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return val;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ret = val;
        has = Iterator::hasNext() ? true : false;
        if (has) val = Iterator::next();
        return ret;
    }
    
    bool hasNext() const {
        return has;
    }
private:
    bool has;
    int val;
};
#endif /* solution_h */
