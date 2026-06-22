#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    ll ans = accumulate(nums.begin(), nums.end(), 0LL);
    sort(nums.begin(), nums.end());
    for(int step=4; step<=n; step+=4){
        for(int i=step-1; i<n; i+=step)
            ans+=nums[i];
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
