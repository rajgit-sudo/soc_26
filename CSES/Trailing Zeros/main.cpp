#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    ll ans=0;
    ll t = 5;
    ll curr = n/t;
    while(curr){
        curr = n/t;
        ans += curr;
        t *= 5;
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
