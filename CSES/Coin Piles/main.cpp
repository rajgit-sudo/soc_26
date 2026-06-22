#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int a, b; cin>>a>>b;
    int sum = a+b;
    if(sum%3!=0){
        cout<<"NO\n";
        return;
    }

    if((a<=2*b) && (b<=2*a))
        cout<<"YES\n";
    else
        cout<<"NO\n";
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


// 11 4
// 9 3
// 7 2
// 5 1
// 3 0
