#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<pair<int, int>> nums; nums.reserve(2*n);
    for(int i=0;i<n;i++){
        int a, b; cin>>a>>b;
        nums.push_back({a, 1});
        nums.push_back({b, -1});
    }
    sort(nums.begin(), nums.end());
    int ans=0, curr=0;
    for(auto i: nums){
        curr += i.second;
        ans = max(ans, curr);
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
