#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];
    sort(nums.rbegin(), nums.rend());

    for(int i=2; i<n; i++){
        if(nums[i] != nums[i-2]%nums[i-1]){
            cout<<"-1\n";
            return;
        }
    }
    cout<<nums[0]<<" "<<nums[1]<<"\n";
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
