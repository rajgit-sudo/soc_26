#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

const int INF = 1e9 + 5;

void solve() {
    int n, target; cin>>n>>target;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];
    vector<int> dp(target+1, INF);
    dp[0]=0;
    for(int i=1; i<=target; i++){
        for(int coin: coins){
            if(i>=coin)
                dp[i] = min(dp[i], dp[i-coin] + 1);
        }
    }
    cout<<(dp[target]==INF?-1:dp[target]);
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
