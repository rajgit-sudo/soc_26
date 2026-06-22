#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n, n), pse(n, -1);
        vector<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.back()]>=nums[i])
                st.pop_back();
            if(!st.empty())
                pse[i] = st.back();
            st.push_back(i);
        }
        st.clear();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.back()]>=nums[i])
                st.pop_back();
            if(!st.empty())
                nse[i] = st.back();
            st.push_back(i);
        }

        int ans=0;
        for(int i=0;i<n;i++)
            ans = max(ans, nums[i] * (nse[i]-pse[i]-1));
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = (matrix[0]).size();
        vector<int> nums(m, 0);

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                    nums[j] = 0;
                else{
                    nums[j]+=1;
                }
            }
            ans = max(ans, largestRectangleArea(nums));
        }
        return ans;
    }
};
