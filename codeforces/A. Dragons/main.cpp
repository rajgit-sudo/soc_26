#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int s,n ; cin>>s>>n;
    vector<pair<int, int>> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i].first>>nums[i].second;
    sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });

    for(int i=0;i<n;i++){
        if(s>nums[i].first){
            s+=nums[i].second;
        }else{
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
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
