#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(const int& i: nums)
            map[i]++;

        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), [&](int a, int b){
            return map[a]>map[b];
        });
        return vector<int>(nums.begin(), nums.begin()+k-1);
    }
};
