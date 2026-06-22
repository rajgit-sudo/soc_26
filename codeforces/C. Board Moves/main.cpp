#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;

void solve() {
    ll n; cin>>n;
    cout<<(n*(n*n-1))/3<<"\n";
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
