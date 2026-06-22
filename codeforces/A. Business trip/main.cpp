#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int k; cin>>k;
    vector<int> nums(12);
    for(int i=0;i<12;i++)
        cin>>nums[i];
    sort(nums.rbegin(), nums.rend());
    int curr=0;
    int ans=0;
    for(int i=0;i<12;i++){
        if(curr<k){
            curr+=nums[i]; ans++;}
        else{
            break;
        }
    }

    if(curr<k)
        cout<<-1;
    else
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
