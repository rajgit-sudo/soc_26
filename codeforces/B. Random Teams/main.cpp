#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll pairs(int k){
    ll t = ll(k);
    ll ans = (t*(t-1))/2;
    return ans;
}

void solve() {
    int n, m; cin>>n>>m;
    ll kmin, kmax;

    int r = n%m;
    kmin = r * pairs(n/m + 1) + (m-r)*pairs(n/m);
    kmax = pairs(n-m+1);
    cout<<kmin<<" "<<kmax;
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
