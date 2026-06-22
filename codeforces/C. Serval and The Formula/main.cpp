#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int x, y; cin>>x>>y;
    if(x==y){
        cout<<-1<<"\n";
        return;
    }

    cout<<(1LL<<59) - max(x,y)<<"\n";
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
