#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    ll maxElement=0, total=0;
    for(int i=0;i<n;i++){
        ll a; cin>>a;
        maxElement = max(maxElement, a);
        total+=a;
    }

    cout<<max(2*maxElement, total);
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
