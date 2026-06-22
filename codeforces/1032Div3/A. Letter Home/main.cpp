#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, s; cin>>n>>s;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    int ans=0;
    if(s<=nums.front()){
        ans = nums.back() - s;
    }else if(s>=nums.back()){
        ans = s - nums.front();
    }else{
        ans = min(s - nums.front(), nums.back() - s) + nums.back() - nums.front();
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

// 1 2 3 4 5 6 7 8 9 10
