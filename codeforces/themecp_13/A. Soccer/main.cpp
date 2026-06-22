#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    ll x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;

    if((x1-y1)*(x2-y2) > 0) // both of same sign (2-1 then became 4-2) so its def possible
        cout<<"YES\n";
    else
        cout<<"NO\n";
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
