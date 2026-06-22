#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<n;i++){
        while(!dq.empty() && dq.front()<=(i-k))
            dq.pop_front();

        while(!dq.empty() && nums[dq.back()]<=nums[i])
            dq.pop_back();
        dq.push_back(i);

        if(i>=k-1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

void solve() {
    int n, k; cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    vector<int> ans = maxSlidingWindow(nums, k);
    for(int i: ans)
        cout<<i<<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in1.txt", "r", stdin);
    freopen("res1.txt", "w", stdout);


    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
