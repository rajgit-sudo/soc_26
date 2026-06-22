#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];

    for(int i=1;i<n-1;i++){
        nums[i]-=(2*nums[i-1]);
        nums[i+1]-=nums[i-1];
        nums[i-1]=0;

        if(nums[i]<0 || nums[i+1]<0){
            cout<<"NO\n";
            return;
        }
    }

    for(int i: nums){
        if(i!=0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
