#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll=long long;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> nums(n);
    unordered_map<int, int> position;
    for (int i=0; i<n; i++){
        nums[i] = i+1;
        position[nums[i]] = i;
    }

    for(int i=0;i<q;i++){
        int k; cin>>k;
        if(position[k]==n-1){
            position[k] = n-2;
            position[nums[n-2]] = n-1;
            swap(nums[n-2], nums[n-1]);
            continue;
        }

        int currIdx = position[k];
        int nextIdx = currIdx + 1;
        position[k] = nextIdx;
        position[nums[nextIdx]] = currIdx;
        swap(nums[currIdx], nums[nextIdx]);
    }


    for(int i: nums)
        cout<<i<<" ";
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
