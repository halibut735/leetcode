#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<Interval>::iterator head = biSearch(intervals, newInterval.start, true);
        vector<Interval>::iterator tail = biSearch(intervals, newInterval.end, false);
        int tmp = 0;
        if ((*head).end >= newInterval.start && (*tail).start <= newInterval.end ){
            cout << "head->start:" << head->start << " tail->end:" << tail->end << endl;
            cout << "case one" << endl;
            intervals.insert(head, Interval((*head).start, (*tail).end));
            intervals.erase(head, tail +1);
        }
        else if ((*head).end <= newInterval.start && (*tail).start >= newInterval.end ){
            cout << "head->start:" << head->start << " tail->end:" << tail->end << endl;
            cout << "case two" << endl;
            intervals.erase(head+1, tail);
            intervals.insert(tail, newInterval);
        }
        else if((*head).end <= newInterval.start && (*tail).start <= newInterval.end){
            cout << "head->start:" << head->start << " tail->end:" << tail->end << endl;
            cout << "case three" << endl;
            tmp = (*tail).end;
            intervals.erase(head+1, tail+1);
            intervals.insert(head+1, Interval(newInterval.start, tmp));
        }
        else{
            cout << "case four" << endl;
            tmp = (*head).start;
            print_vec(intervals);
            tail = intervals.insert(tail, Interval(tmp, newInterval.end));
            print_vec(intervals);
            intervals.erase(head, tail);
            print_vec(intervals);
        }
        return intervals;
    }


 private:
    void print_vec(vector<Interval> & vec){
        for (vector<Interval>::iterator it = vec.begin(); it < vec.end(); ++it){
            cout << " start: " << it->start  << " end: " << it->end << " ";
        }
        cout << endl;
    }
    vector<Interval>::iterator biSearch(vector<Interval> &intervals, const int &val, const bool &is_up){
        vector<Interval>::iterator head, tail, mid;
        head = intervals.begin();
        tail = intervals.end() ;
        mid = head + (tail-head)/2;
        int tmp = is_up? (*mid).start: (*mid).end;
        while (mid != tail && mid != head){
            tmp = is_up?(*mid).start:(*mid).end;
            if ((is_up && tmp <= val) ||  (!is_up && tmp < val)){
                head = mid;
            }
            else {
                tail = mid;
            }
            mid = head + (tail-head)/2;
        }
        if (is_up)
            return head;
        else
            return tail;
    }
};
