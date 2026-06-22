#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    vector<int> sortedNums(nums.begin(), nums.end());
    sort(sortedNums.begin(), sortedNums.end());

    vector<ll> prefixSums(n);
    prefixSums[0] = sortedNums[0];
    for(int i=1; i<n; i++)
        prefixSums[i] = prefixSums[i-1] + sortedNums[i];

    vector<int> ans(n);
    ans[n-1] = n-1;
    for(int i=n-2; i>=0; i--){
        if(prefixSums[i] >= sortedNums[i+1]){
            ans[i] = ans[i+1];
        }else {
            ans[i] = i;
        }
    }

    unordered_map<int, int> ansMap;
    for(int i=0;i<n;i++)
        ansMap[sortedNums[i]] = ans[i];

    for(int i=0;i<n;i++)
        cout<<ansMap[nums[i]]<<" ";
    cout<<"\n";
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
