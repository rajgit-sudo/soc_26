#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

const int MOD = 1e9+7;

void solve() {
    int n, target; cin>>n>>target;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];

    vector<int> dp(target+1, 0);
    dp[0]=1;
    for(int coin: coins){
        for(int i=1; i<=target; i++){
            if(i>=coin)
                dp[i] = (dp[i] + dp[i-coin])%MOD;
        }
    }
    cout<<dp[target];
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
