#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    vector<int> dp(n, 2e9 + 5);
    dp[0]=0;
    for(int i=1; i<n; i++){
        for(int jump=1; jump<=min(k, i); jump++){
            dp[i] = min(dp[i], dp[i-jump] + abs(nums[i] - nums[i-jump]));
        }
    }
    cout<<dp[n-1];
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
