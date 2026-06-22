#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<vector<int>> nums(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>nums[i][j];
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(n, -1e12));
    dp[0][0] = nums[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j<i)
                dp[i][j] = max(dp[i][j], nums[i][j] + dp[i-1][j]);
            if(j>0)
                dp[i][j] = max(dp[i][j], nums[i][j] + dp[i-1][j-1]);
        }
    }
    cout<<*max_element(dp[n-1].begin(), dp[n-1].end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("slalom.in", "r", stdin);
    // freopen("slalom.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
