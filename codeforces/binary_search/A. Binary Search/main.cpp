#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    for(int i=0;i<k;i++){
        int a; cin>>a;
        cout<<(binary_search(nums.begin(), nums.end(), a)?"YES\n":"NO\n");
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
