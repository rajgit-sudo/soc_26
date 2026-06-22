#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

struct Happiness{
    int a, b, c;
};

void solve() {
    int n; cin>>n;
    vector<Happiness> nums; nums.reserve(n);
    for(int i=0;i<n;i++){
        int a, b, c; cin>>a>>b>>c;
        nums.emplace_back(Happiness(a, b, c));
    }

    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    dp[0][0]=0;
    dp[0][1]=0;
    dp[0][2]=0;

    for(int i=1; i<=n; i++){
        dp[i][0] = max(dp[i-1][1] + nums[i-1].a, dp[i-1][2] + nums[i-1].a);
        dp[i][1] = max(dp[i-1][0] + nums[i-1].b, dp[i-1][2] + nums[i-1].b);
        dp[i][2] = max(dp[i-1][0] + nums[i-1].c, dp[i-1][1] + nums[i-1].c);
    }

    cout<<max({dp[n][0], dp[n][1], dp[n][2]});
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
