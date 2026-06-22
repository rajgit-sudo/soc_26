#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    int left=0;
    ll ans=0;
    unordered_map<int, int> freq;
    for(int right=0;right<n;right++){
        freq[nums[right]]++;

        while(int(freq.size())>k){
            freq[nums[left]]--;
            if(freq[nums[left]] == 0) freq.erase(nums[left]);
            left++;
        }

        ans += (right - left+1);
    }
    cout<<ans;
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

// 1 2 3 1 1
