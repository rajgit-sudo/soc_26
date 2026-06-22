#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <sys/types.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int ans = 1;
    int left=0;
    multiset<int> ms;
    for(int right=0; right<n; right++){
        ms.insert(nums[right]);

        while(*ms.rbegin() - *ms.begin() > 1){
            ms.erase(ms.find(nums[left]));
            left++;
        }
        ans = max(ans, right-left+1);
    }
    cout<<ans<<"\n";
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
