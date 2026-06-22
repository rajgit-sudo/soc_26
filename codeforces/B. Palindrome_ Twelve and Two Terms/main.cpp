#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    if(n%12==10){
        if(n==10){
            cout<<"-1\n";
            return;
        }

        cout<<22<<" "<<((n/12)-1)*12<<"\n";
    }else{
        cout<<n%12<<" "<<(n/12)*12<<"\n";
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
