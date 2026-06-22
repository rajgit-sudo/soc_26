#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int r, h, c, w; cin>>h>>w>>r>>c;

    int ans=0;
    if(r>1) ans++;
    if(r<h) ans++;
    if(c>1) ans++;
    if(c<w) ans++;
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
