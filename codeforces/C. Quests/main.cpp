#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    ll ans=0, currSum = 0;
    ll maxB = b[0];
    ll extra = max(k-n, 0);
    for(int i=0; i<min(k, n); i++){
        currSum += a[i];
        maxB = max(maxB, b[i]);
        ans = max(ans, currSum + (min(k, n)-1-i + extra)*maxB);
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
