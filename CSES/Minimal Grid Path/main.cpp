#include <bits/stdc++.h>
#include <cerrno>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x; cin>>x;
            grid[i][j] = (x-'A');
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[0][0] = grid[0][0];
    for(int i=1; i<n; i++){
        dp[0][i] = dp[0][i-1] + grid[0][i];
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = grid[i][j];
            if(grid[i-1][j] <= grid[i][j-1])
                dp[i][j] += dp[i-1][j];
            else
                dp[i][j] += dp[i][j-1];
        }
    }

    int i =n-1, j=n-1;
    string ans = "";
    while(i>=0 && j>=0){
        ans.push_back(grid[i][j] + 'A');
        if(i==0)
            j--;
        else if(j==0)
            i--;
        else{
            if(dp[i-1][j] <= dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    // ans.push_back(grid[0][0] + 'A');
    reverse(ans.begin(), ans.end());
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
