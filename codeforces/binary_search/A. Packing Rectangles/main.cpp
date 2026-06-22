#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll=long long;

void solve() {
    ll w, h, n; cin>>w>>h>>n;

    ll low = 1, high = 1, mid;

    auto valid = [&](ll side){
        if((side/h) * (side/w) >= n)
            return true;
        return false;
    };

    while(!valid(high)) high*=2;
    ll ans = high;

    while(low<=high){
        mid = midpoint(low, high);
        if(valid(mid)){
            ans = min(ans, mid);
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<ans<<"\n";
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
