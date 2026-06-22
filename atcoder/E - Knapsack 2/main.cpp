#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n, w; cin>>n>>w;
    vector<ll> weights(n), values(n);
    ll totalValue = 0;
    for(ll i=0;i<n;i++){
        cin>>weights[i];
        cin>>values[i];
        totalValue+=values[i];
    }

    const ll INF = 1e18;
    vector<ll> dp(totalValue+1, INF);
    dp[0]=0;
    for(ll i=0; i<n; i++){
        for(ll currValue = totalValue; currValue >= values[i]; currValue --){
            dp[currValue] = min(dp[currValue], dp[currValue - values[i]] + weights[i]);
        }
    }

    ll ans=0;
    for(ll i=0; i<=totalValue; i++){
        if(dp[i]<=w)
            ans=i;
    }
    cout<<ans;
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
