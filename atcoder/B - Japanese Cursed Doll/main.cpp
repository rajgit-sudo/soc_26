#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, t, p; cin>>n>>t>>p;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(), nums.end());
    auto it = lower_bound(nums.begin(), nums.end(), t);
    int index = it - nums.begin();
    int numberOfPeople = distance(it, nums.end());
    if(numberOfPeople>=p){
        cout<<0;
        return;
    }else{
        index -= (p - numberOfPeople);
        cout<<(t-nums[index]);
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
