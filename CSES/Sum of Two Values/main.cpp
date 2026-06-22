#include <algorithm>
#include <bits/stdc++.h>
#include <sys/types.h>
#include <unordered_map>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, target; cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    map<int, int> map;
    vector<int> ans = {-1, -1};
    for(int i=0; i<n; i++){
        if(map.contains(target - nums[i])){
            ans[0] = i;
            ans[1] = map[target-nums[i]];
            break;
        }
        map[nums[i]]=i;
    }

    if(ans[0]==-1 && ans[1]==-1){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<ans[0]+1<<" "<<ans[1]+1;
    }
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
