#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i: nums){
            if(mass>i)
                mass+=i;
            else
                return false;
        }
        return true;
    }
};
