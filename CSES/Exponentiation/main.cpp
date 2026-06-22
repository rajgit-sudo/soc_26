#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD = 1e9+7;

void solve() {
    ll a, b; cin>>a>>b;
    a = (a%MOD);

    ll res = 1;
    while(b>0){
        if(b%2==1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b/=2;
    }

    cout<<res<<"\n";
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
