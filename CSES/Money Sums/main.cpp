#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    int sumMax=0;
    for (int i=0; i<n; i++){
        cin>>nums[i];
        sumMax+=nums[i];
    }

    sort(nums.begin(), nums.end());
    vector<bool> dp(sumMax+1, false);
    dp[0] = true;
    for(int i=1; i<=n; i++){
        for(int target = sumMax; target>=0; target--){
            if(target>=nums[i-1])
                dp[target] = (dp[target]|dp[target-nums[i-1]]);
        }
    }

    vector<int> ans;
    for(int i=1; i<=sumMax; i++){
        if(dp[i])
            ans.push_back(i);
    }

    cout<<int(ans.size())<<"\n";
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
