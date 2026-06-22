#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll=long long;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=n-1, mid;
        while(i<j){
            mid = midpoint(i, j);

            if(mid%2==1)
                mid--;

            if(nums[mid]==nums[mid+1])
                i = mid+2;
            else
                j = mid;
        }

        return nums[i];
    }
};
