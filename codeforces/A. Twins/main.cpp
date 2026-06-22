#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    int total=0;
    for (int i=0; i<n; i++){
        cin>>nums[i];
        total+=nums[i];
    }
    sort(nums.rbegin(), nums.rend());
    int currSum=0;
    for(int i=0;i<n;i++){
        if(currSum + 2*nums[i] > total){
            cout<<i+1;
            return;
        }

        currSum += nums[i];
        total -= nums[i];
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
