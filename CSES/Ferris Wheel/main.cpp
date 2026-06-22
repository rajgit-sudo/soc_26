#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, x; cin>>n>>x;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(), nums.end());
    int i=0, j=n-1;
    int ans=0;
    while(i<=j){
        int total = nums[i] + nums[j];
        if(i==j)
            total -= nums[i];
        if(total>x){
            j--;
        }else{
            i++; j--;
        }
        ans++;
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
