#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<pair<int, int>> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i].first>>nums[i].second;

    sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.second == b.second)
            return a.second > b.second;
        return a.second < b.second;
    });

    int ans=0;
    int endTime = -1;
    for(auto i: nums){
        if(i.first >= endTime){
            ans++;
            endTime = i.second;
        }
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
