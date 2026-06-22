#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    int ans=0;
    set<int> set;
    int i=0, j=0;
    while(j<n){
        while(set.contains(nums[j])){
            set.erase(nums[i]);
            i++;
        }

        set.insert(nums[j]);
        j++;
        ans = max(ans, int(set.size()));
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
