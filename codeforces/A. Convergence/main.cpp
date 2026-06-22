#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

int groupCalls(vector<int>& nums, int target){
    int requiredSmaller = 0, requiredLarger=0, notRequired=0;
    for(int i: nums){
        if(i!=target){
            if(i>target)
                requiredLarger++;
            else
                requiredSmaller++;
        }else
            notRequired++;
    }

    return max(requiredLarger, requiredSmaller);
}

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(), nums.end());

    int ans = 1e9;
    int median;
    if(n%2==1){
        median = nums[n/2];
        ans = min(ans, groupCalls(nums, median));
    }else{
        median = nums[n/2];
        ans = min(ans, groupCalls(nums, median));
        median = nums[n/2+1];
        ans = min(ans, groupCalls(nums, median));
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
