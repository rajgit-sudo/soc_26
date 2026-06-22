#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]<=nums[i])
                st.pop();
            if(!st.empty())
                nge[i] = st.top();
            st.push(i);
        }

        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            if(nge[i]!=-1)
                ans[i] = nge[i] - i;
        }
        return ans;
    }
};
