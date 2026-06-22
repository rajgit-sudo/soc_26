#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, target; cin>>n>>target;
    vector<pair<int, int>> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i].first;
        nums[i].second = i+1;
    }

    sort(nums.begin(), nums.end());
    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i].first == nums[i-1].first) continue;
        int j=i+1, k=n-1;
        while(j<k){
            int currSum = nums[i].first + nums[j].first + nums[k].first;
            if(currSum == target){
                cout<<nums[i].second<<" "<<nums[j].second<<" "<<nums[k].second;
                return;
            }else if(currSum < target){
                while(j<k && nums[j].first == nums[j+1].first) j++;
                j++;
            }else{
                while(j<k && nums[k].first == nums[k-1].first) k--;
                k--;
            }
        }
    }
    cout<<"IMPOSSIBLE";
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
