#include <bits/stdc++.h>
#include <sys/types.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n+1);
    for(int i=0;i<n;i++){
        int a; cin>>a;
        nums[a] = i;
    }

    int ans=1;
    for(int i=1; i<n; i++){
        if(nums[i+1] < nums[i]){
            ans++;
        }
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
