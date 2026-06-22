#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using ll=long long;
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {

    }

    void addNum(int num) {
        if(left.empty() || num<=left.top())
            left.push(num);
        else
            right.push(num);

        if(left.size() > right.size()+1){
            right.push(left.top());
            left.pop();
        }

        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        int n = left.size() + right.size();
        if(n%2==1)
            return double(left.top());
        else
            return ((left.top() + right.top())/2.0);
    }
};
