#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    long double n; cin>>n;
    double tolerance = 1e-7;
    long double low = 0, high = 1e5, mid;
    long double ans = 0;
    while(high-low>=tolerance){
        mid = low + (high-low)/2.0;
        if((mid*mid + sqrtl(mid))<=n){
            ans = mid;
            low = mid;
        }else {
            high = mid;
        }
    }
    cout<<fixed << setprecision(10)<<ans;
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
