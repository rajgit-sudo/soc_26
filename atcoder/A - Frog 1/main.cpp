#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    vector<int> dp(n, 0);
    for(int i=1; i<n; i++){
        if(i==1)
            dp[i] = dp[i-1] + abs(nums[i] - nums[i-1]);
        else
            dp[i] = min(dp[i-1] + abs(nums[i] - nums[i-1]), dp[i-2] + abs(nums[i] - nums[i-2]));
    }
    cout<<dp[n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
