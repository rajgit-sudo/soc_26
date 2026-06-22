#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    ll sum=0;
    for(int i=0; i<n-1; i++){
        ll a; cin>>a;
        sum+=a;
    }

    ll expectedSum = (n * (n+1)) /2;
    cout<<expectedSum - sum;
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
