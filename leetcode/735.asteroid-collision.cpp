#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            bool destroyed = false;

            if(nums[i]>0){
                ans.push_back(nums[i]);
                continue;
            }

            while(nums[i]<0 && ans.back()>0){
                if(-nums[i]==ans.back()){
                    ans.pop_back();
                    destroyed = true;
                }else if(-nums[i] > ans.back()){
                    ans.pop_back();
                }else{
                    destroyed=true;
                }
            }

            if(!destroyed)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};
