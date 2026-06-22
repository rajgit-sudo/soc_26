#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

ll cost(const vector<int>& nums, int x){
    ll ans=0;
    for(const int& i: nums)
        ans+=abs(i-x);
    return ans;
}

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    if(n%2==1){
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        int median = nums[n/2];
        cout<<cost(nums, median);
    }else{
        nth_element(nums.begin(), nums.begin() + n/2 - 1, nums.end());
        int median = nums[n/2 -1];
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        median = (median + nums[n/2])/2;
        cout<<min(cost(nums, median), cost(nums, median+1));
    }
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
