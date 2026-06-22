#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];

    sort(nums.begin(), nums.end());
    int q; cin>>q;
    for(int i=0;i<q;i++){
        int l, r; cin>>l>>r;
        auto it1 = lower_bound(nums.begin(), nums.end(), l);
        auto it2 = upper_bound(nums.begin(), nums.end(), r);
        cout<<distance(it1, it2)<<" ";
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
