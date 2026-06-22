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

    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i].first == nums[i-1].first) continue;
        for(int j=i+1; j<n-2; j++){
            int k=j+1, p=n-1;
            while(k<p){
                int currSum = nums[i].first + nums[j].first + nums[k].first + nums[p].first;
                if(currSum == target){
                    cout<<nums[i].second<<" "<<nums[j].second<<" "<<nums[k].second<<" "<<nums[p].second;
                    return;
                }else if(currSum < target){
                    while(k<p && nums[k].first == nums[k+1].first) k++;
                    k++;
                }else {
                    while(k<p && nums[p].first == nums[p-1].first) p--;
                    p--;
                }
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
