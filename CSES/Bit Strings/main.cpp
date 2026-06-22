#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin>>n;
    int ans = 1;
    for(int i=0;i<n;i++){
        ans = (ans*2)%MOD;
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
