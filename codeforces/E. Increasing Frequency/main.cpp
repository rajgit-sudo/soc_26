#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n, c; cin>>n>>c;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    vector<int> prefixC(n+1, 0);
    for(int i=1; i<=n; i++)
        prefixC[i] = prefixC[i-1] + (nums[i-1]==c);

    vector<int> dp(5e5+1, 0);
    int maxExtra=0;
    for(int i=1; i<=n; i++){
        int x = nums[i-1];
        if(x!=c){
            dp[x] = max(dp[x], prefixC[i-1]) +1;
            maxExtra = max(maxExtra, dp[x] - prefixC[i]);
        }
    }

    cout<<prefixC[n] + maxExtra<<"\n";
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
