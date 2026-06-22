#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll=long long;
class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq(nums.begin(), nums.end());

        while(pq.size()>1){
            int biggest = pq.top(); pq.pop();
            int secondBiggest = pq.top(); pq.pop();
            if(biggest > secondBiggest)
                pq.push(biggest-secondBiggest);
        }

        if(pq.empty())
            return 0;
        return pq.top();
    }
};
