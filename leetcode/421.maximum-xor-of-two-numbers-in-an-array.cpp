#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        vector<int> MSB(n);
        for(int i=0; i<n; i++){
            MSB[i] = bit_width((unsigned)nums[i]) - 1;
        }

        auto maxMSB = max_element(MSB.begin(), MSB.end());
        int maxMSBIdx = maxMSB - MSB.begin();
        int maxMSBVal = MSB[maxMSBIdx];

        int secondMSBVal = 0;
        for(int i=0; i<n; i++){
            int x = MSB[i];
            if(x!=maxMSBVal){
                if(x>secondMSBVal){
                    secondMSBVal = x;
                }
            }
        }

        if(secondMSBVal != maxMSBVal){
            int ans = 0;
            for(int i=0;i<n;i++){
                if(MSB[i] == secondMSBVal){
                    ans = max(ans, nums[maxMSBIdx] ^ nums[i]);
                }
            }
            return ans;
        }else{
            sort(nums.begin(), nums.end());
            return (nums.front() ^ nums.back());
        }
    }
};
