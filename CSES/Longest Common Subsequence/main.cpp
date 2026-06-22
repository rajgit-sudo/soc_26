#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> s1(n), s2(m);
    for(int i=0;i<n;i++)
        cin>>s1[i];
    for(int i=0;i<m;i++)
        cin>>s2[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // dp[i][j]: length of longest increasing subsequence s1[0...i] and s2[0...j]
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int LCS = dp[n][m];
    cout<<LCS<<"\n";
    vector<int> ans; ans.reserve(LCS);
    int i=n, j=m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--; j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    for(int i: ans)
        cout<<i<<" ";
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
