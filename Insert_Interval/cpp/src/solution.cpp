#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

int main()
{
    vector<Interval> vec;
    Solution sol;
    cout << "hello" <<endl;
    vec.push_back(Interval(1, 5));
    vec.push_back(Interval(6 , 9));
    sol.insert(vec, Interval(8, 11));
    return 1;
}
