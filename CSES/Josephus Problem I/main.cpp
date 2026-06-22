#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void josephus(vector<int>& nums){
    int n = nums.size();
    if(n==1){
        cout<<nums[0]<<" ";
        return;
    }
    for(int i=1; i<n; i+=2)
        cout<<nums[i]<<" ";

    vector<int> next; next.reserve(n/2);
    if(n%2==1)
        next.push_back(nums.back());

    for(int i=0; i<n-1; i+=2)
        next.push_back(nums[i]);
    josephus(next);
}

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=1;i<=n;i++)
        nums[i-1]=i;
    josephus(nums);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
