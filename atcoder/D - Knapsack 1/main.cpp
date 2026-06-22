#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n, w; cin>>n>>w;
    vector<ll> weights(n), values(n);
    for(ll i=0;i<n;i++){
        cin>>weights[i];
        cin>>values[i];
    }
    vector<ll> dp(w+1);
    dp[0]=0;
    for(ll i=0; i<n; i++){
        for(ll capacity = w; capacity>=weights[i]; capacity--){
            dp[capacity] = max(dp[capacity], dp[capacity - weights[i]] + values[i]);
        }
    }
    cout<<dp[w];
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
