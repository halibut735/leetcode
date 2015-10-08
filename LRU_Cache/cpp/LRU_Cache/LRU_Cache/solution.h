//
//  solution.h
//  LRU_Cache
//
//  Created by 中央政治局常委 on 15/9/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        head = tail = -1;
        cache.resize(capacity);
        for (int i = 0; i < capacity; ++i) {
            cache[i].pre = cache[i].next = -1;
            que_unused_id.push(i);
        }
    }
    
    int get(int key) {
        if (!reflection.count(key)) {
            return -1;
        }
        //update!!!
        int pos = reflection[key];
        if (pos == head) {
            return cache[pos].val;
        }
        if (pos == tail) {
            tail = cache[pos].pre == -1 ? tail : cache[pos].pre;
        }
        if (cache[pos].pre != -1) {
            cache[cache[pos].pre].next = cache[pos].next;
        }
        if (cache[pos].next != -1) {
            cache[cache[pos].next].pre = cache[pos].pre;
        }
        cache[pos].pre = -1;
        cache[pos].next = head;
        cache[head].pre = pos;
        head = pos;
        return cache[pos].val;
    }
    
    void set(int key, int value) {
        if (!reflection.count(key)) {
            if (que_unused_id.empty()) {
                //delete the last one
                reflection.erase(reflection.find(cache[tail].key));
                que_unused_id.push(tail);
                
                if (cache[tail].pre != -1) {
                    cache[cache[tail].pre].next = -1;
                    int tmp = cache[tail].pre;
                    cache[tail].pre = -1;
                    tail = tmp;
                }
                else {
                    head = tail = -1;
                }
            }
            //add new one
            int id_new = que_unused_id.front();
            que_unused_id.pop();
            cache[id_new].val = value;
            cache[id_new].key = key;
            cache[id_new].pre = -1;
            cache[id_new].next = head;
            if (head != -1) {
                cache[head].pre = id_new;
            }
            tail = tail == -1 ? id_new : tail;
            head = id_new;
            reflection[key] = id_new;
        }
        else {
            //update!!!
            int pos = reflection[key];
            cache[pos].val = value;
            if (pos == head) {
                return ;
            }
            if (pos == tail) {
                tail = cache[pos].pre == -1 ? tail : cache[pos].pre;
            }
            if (cache[pos].pre != -1) {
                cache[cache[pos].pre].next = cache[pos].next;
            }
            if (cache[pos].next != -1) {
                cache[cache[pos].next].pre = cache[pos].pre;
            }
            cache[pos].pre = -1;
            cache[pos].next = head;
            cache[head].pre = pos;
            head = pos;
        }
    }
private:
    struct node{
        int key, val;
        int pre, next;
    };
    vector<node> cache;
    int head, tail;
    queue<int> que_unused_id;
    unordered_map<int, int> reflection;
};

#endif /* solution_h */
