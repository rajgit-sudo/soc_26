#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    vector<int> ans = {5, 5, 7};
    vector<int> nums(3);
    for(int i=0;i<3;i++)
        cin>>nums[i];
    sort(nums.begin(), nums.end());
    cout<<(ans==nums?"YES":"NO");
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
