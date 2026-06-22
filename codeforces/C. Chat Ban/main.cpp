#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll=long long;

void solve() {
    int k; cin>>k;
    ll x; cin>>x;
    ll low = 0, high = 2*k -1, mid;
    int ans=0;

    auto valid = [&](ll mid){
        if(mid*(mid+1) > 2 * x)
            return false;
        return true;
    };

    while(low<=high){
        mid = midpoint(low, high);
        if(valid(mid)){
            ans = max(ans, int(mid));
            low = mid+1;
        }else{
            high = mid-1;
        }
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
