#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int b, c, h; cin>>b>>c>>h;
    int bread = b;
    int slices = c + h;
    int ans = 2; bread-=2;

    if(bread==0){
        cout<<3<<"\n";
        return;
    }else if(bread<slices){
        ans += 2*bread+1;
    }else if(bread>=slices){
        ans += 2*slices-1;
    }

    cout<<ans<<"\n";
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
