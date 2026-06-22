#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, x; cin>>n>>x;
    ll totalPages=0;
    vector<pair<int, int>> nums(n); // price, pages
    for(int i=0;i<n;i++)
        cin>>nums[i].first;
    for(int i=0;i<n;i++){
        cin>>nums[i].second;
        totalPages += nums[i].second;
    }

    vector<int> dp(x+1, 0);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int capacity = x; capacity>=0; capacity--)
            if(capacity>=nums[i].first)
                dp[capacity] = max(dp[capacity], dp[capacity-nums[i].first] + nums[i].second);
    }
    cout<<dp[x];
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
