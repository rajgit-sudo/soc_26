#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int celing(int a, int b){
    return (a+b-1)/b;
}

void solve() {
    int n, x, y, z; cin>>n>>x>>y>>z;
    cout<<min(celing(n, x+y), celing(n+10*y*z, x+10*y))<<"\n";
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
