#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;


void solve() {
    int n, k; cin>>n>>k;
    vector<pair<int, int>> nums(n);
    for (int i=0; i<n; i++){
        int a; cin>>a;
        int r = (a%k);
        if(r==0)
            r = k;
        nums[i] = {r, i};
    }

    sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    });

    for(auto [monstor, idx]: nums){
        cout<<idx+1<<" ";
    }
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
