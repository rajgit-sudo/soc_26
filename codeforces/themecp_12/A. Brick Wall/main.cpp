#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n, m; cin>>n>>m;
    ll ans = n * (m/2);
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
