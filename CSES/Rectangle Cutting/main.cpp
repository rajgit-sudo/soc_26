#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

const ll INF = 1e18;

void solve() {
    ll a, b; cin>>a>>b;
    vector<vector<ll>> dp(a+1, vector<ll>(b+1, INF));
    for(int i=0; i<=min(a, b); i++)
        dp[i][i] = 0;

    for(int i=2; i<=a; i++)
        dp[i][1] = i-1;
    for(int i=2; i<=b; i++)
        dp[1][i] = i-1;

    for(int i=2; i<=a; i++){
        for(int j=2; j<=b; j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }

            for(int cut = 1; cut<i; cut++)
                dp[i][j] = min(dp[i][j], 1 + dp[cut][j] + dp[i-cut][j]);
            for(int cut = 1; cut<j; cut++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][cut] + dp[i][j-cut]);
        }
    }
    cout<<dp[a][b];
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
