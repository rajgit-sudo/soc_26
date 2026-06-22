#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll=long long;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = 0;
        ll curr=0;
        int i=0, j=0;
        unordered_set<int> set;
        while(j<n){
            set.insert(nums[j]);
            curr+=nums[j];

            if(int(set.size())==k)
                ans = max(ans, curr);

            while(int(set.size())>=k){
                set.erase(nums[i]);
                curr -= nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};
