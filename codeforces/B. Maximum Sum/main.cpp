#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> nums(n);
    ll totalSum = 0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        totalSum += nums[i];
    }
    ll ans = 0;
    sort(nums.begin(), nums.end());
    vector<ll> prefixSum(n+1, 0);
    for(int i=0; i<n; i++)
        prefixSum[i+1] = prefixSum[i] + nums[i];

    for(int i=0; i<=k; i++){
        int leftRemoved = 2*i;
        int rightRemoved = (k-i);
        ans = max(ans, prefixSum[n - rightRemoved] - prefixSum[leftRemoved]);
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
