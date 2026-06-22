#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    ll x,y; cin>>x>>y;

    ll ans;
    if(x==y){
        ans = x*x - x + 1;
    }else if(x>y){
        if(x%2==1)
            ans = x*x - 2*x + y + 1;
        else
            ans = x*x - y + 1;
    }else{
        if(y%2==1)
            ans = y*y - x + 1;
        else
            ans = y*y - 2*y + x + 1;
    }
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
