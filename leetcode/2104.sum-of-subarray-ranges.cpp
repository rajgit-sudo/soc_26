#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    void clear_stack(stack<int>& st){
        while(!st.empty())
            st.pop();
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        ll maxSum=0, minSum=0;
        vector<ll> nge(n, n), pge(n, -1), nse(n, n), pse(n, -1);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i])
                st.pop();
            if(!st.empty())
                pge[i] = st.top();
            st.push(i);
        }
        clear_stack(st);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i])
                st.pop();
            if(!st.empty())
                nge[i] = st.top();
            st.push(i);
        }
        clear_stack(st);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(!st.empty())
                pse[i] = st.top();
            st.push(i);
        }
        clear_stack(st);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i])
                st.pop();
            if(!st.empty())
                nse[i] = st.top();
            st.push(i);
        }


        for(int i=0;i<n;i++){
            maxSum += (i-pge[i])*(nge[i]-i)*nums[i];
            minSum += (i-pse[i])*(nse[i]-i)*nums[i];
        }
        return (maxSum - minSum);
    }
};
