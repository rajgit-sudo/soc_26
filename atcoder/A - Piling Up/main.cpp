#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    if(1<=n && n<=99){
        cout<<(100-n);
    }else if(100<=n && n<=199){
        cout<<(200-n);
    }else if(200<=n && n<=299){
        cout<<(300-n);
    }
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
