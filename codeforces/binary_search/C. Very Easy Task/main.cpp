#include <bits/stdc++.h>
#include <ctime>
#include <numeric>
#include <sys/types.h>
using namespace std;
using ll=long long;

void solve() {
    ll n, x, y; cin>>n>>x>>y;
    if(x<y)
        swap(x, y);

    ll low=1, high = 1e18, mid;
    ll ans = high;

    auto valid = [&](ll timeLimit){
        ll leftToCopy = n-1;
        ll timeLeft = timeLimit - y;
        if(timeLeft<0)
            return false;

        return ((timeLeft/x) + (timeLeft/y)) >= leftToCopy;
    };

    while(low<=high){
        mid = midpoint(low, high);
        if(valid(mid)){
            ans = min(ans, mid);
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<ans;
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
