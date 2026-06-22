#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    vector<pair<int, int>> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i].first>>nums[i].second;

    sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    multiset<int> ms;
    for(int i=0;i<k;i++)
        ms.insert(0);

    int ans = 0;
    for(int i=0;i<n;i++){
        auto it = ms.upper_bound(nums[i].first);

        if(it==ms.begin())
            continue;
        it--;
        ms.erase(it);
        ms.insert(nums[i].second);
        ans++;
    }
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in2.txt", "r", stdin);
    // freopen("res2.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
