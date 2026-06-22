#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n, a, b; cin>>n>>a>>b;
    if(a*2 < b){
        cout<<n*a;
    }else if(a*2>=b){
        if(n%2==0)
            cout<<b*(n/2);
        else
            cout<<b*(n-1)/2 + a;
    }
    cout<<"\n";
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
