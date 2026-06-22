#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    unordered_map<int, int> freqMap;
    vector<int> nums(4*n);
    for(int i=0;i<4*n;i++){
        cin>>nums[i];
        freqMap[nums[i]]++;
    }

    for(auto [key, value]: freqMap){
        if(value%2==1){
            cout<<"NO\n";
            return;
        }
    }

    sort(nums.begin(), nums.end());

    int prod = nums.front() * nums.back();
    for(int i=1; i<2*n; i++){
        if((nums[i]*nums[4*n-1-i]!=prod)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in1.txt", "r", stdin);
    // freopen("res1.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
