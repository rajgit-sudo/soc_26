#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin>>n;
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int dice=1; dice<=min(6, i); dice++)
            dp[i] = (dp[i] + dp[i-dice])%MOD;
    }
    cout<<dp[n];
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
