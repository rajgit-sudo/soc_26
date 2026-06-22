#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void backtrack(vector<ll>& nums, ll totalSum, ll& ans, ll currSum=0, int index=0){
    if(index>=int(nums.size())){
        ans = min(ans, abs(currSum - abs(currSum - totalSum)));
        return;
    }

    backtrack(nums, totalSum, ans, currSum+nums[index], index+1);
    backtrack(nums, totalSum, ans, currSum, index+1);
}

void solve() {
    int n; cin>>n;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    ll total = accumulate(nums.begin(), nums.end(), 0LL);
    ll ans = total;
    backtrack(nums, total, ans);
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
