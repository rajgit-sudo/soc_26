#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    unordered_set<int> set;
    int l=0;
    int ans=n;
    bool possible = false;
    for(int r=0; r<n; r++){
        while(set.contains(nums[r])){
            possible = true;
            ans = min(ans, r-l+1);
            set.erase(nums[l]);
            l++;
        }

        set.insert(nums[r]);
    }

    cout<<(possible?ans:-1)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in1.txt", "r", stdin);
    // freopen("res1.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
