#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    ll ans=nums[0];
    ll currSum = nums[0];
    for(int i=1; i<n; i++){
        if(currSum<0)
            currSum = 0;

        if(abs(nums[i] - nums[i-1])%2==1)
            currSum += nums[i];
        else
            currSum = nums[i];
        ans = max(ans, currSum);
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
