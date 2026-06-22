#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
using ll=long long;

ll alala(ll x){
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}

void solve() {
    ll x, y; cin>>x>>y;
    vector<ll> dp(10, 0);
    dp[0] = x;
    dp[1] = y;

    for(ll i=2; i<10; i++)
        dp[i] = alala(dp[i-1] + dp[i-2]);
    cout<<dp.back();
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
