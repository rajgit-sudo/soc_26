#include <bits/stdc++.h>
#include <bit>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    cout<<bit_floor((unsigned)n)-1<<"\n";
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
