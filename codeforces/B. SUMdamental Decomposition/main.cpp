#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n, x; cin>>n>>x;
    int bits=__builtin_popcountll(x);

    if (n<=bits){
        cout<<x<<"\n";return;
    }

    if ((n-bits)%2==0)cout<<x+n-bits<<"\n";
    else{
        if (x>1){cout<<x+n-bits+1<<"\n";return;}
        if (x==1){cout<<n+3<<"\n";return;}
        else{
            if (n==1){cout<<-1<<"\n";return;}
            else cout<<n+3<<"\n";
        }
    }
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
