#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int dist(int l, int t, int n){
    if(t>=l) return t-l;
    return n-l+t;
}

void solve() {
    int n, q; cin>>n>>q;
    ll ans=0;

    int l = 1, r = 2;
    for(int i=0;i<q;i++){
        char h; int t;
        cin>>h>>t;

        if(h=='L'){
            int cw = dist(l, t, n);
            int ccw = dist(t, l, n);

            if(dist(l, r, n) < cw)
                ans+=ccw;
            else
                ans+=cw;

            l = t;
        }else{
            int cw = dist(r, t, n);
            int ccw = dist(t, r, n);
            if(dist(r, l, n) < cw)
                ans+=ccw;
            else
                ans+=cw;

            r = t;
        }
    }
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in3.txt", "r", stdin);
    // freopen("res3.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
