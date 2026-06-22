#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    vector<int> tailIndices;
    vector<int> parent(n, -1);
    for(int i=0;i<n;i++){
        auto it = lower_bound(tailIndices.begin(), tailIndices.end(), i, [&](int idx, int val){
            return nums[idx] < nums[val];
        });

        if(it==tailIndices.end()){
            if(!tailIndices.empty())
                parent[i] = tailIndices.back();
            tailIndices.push_back(i);
        }else{
            int pos = distance(tailIndices.begin(), it);
            tailIndices[pos] = i;
            parent[i] = tailIndices[pos-1];
        }
    }

    vector<int> lis;
    int curr = tailIndices.back();
    while(curr!=-1){
        lis.push_back(nums[curr]);
        curr = parent[curr];
    }
    reverse(lis.begin(), lis.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in1.txt", "r", stdin);
    // freopen("res1.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
