#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];

    set<pair<int, int>> set;
    for(int i=0;i<n;i++){
        int a = i+1;
        int b = nums[i];
        if(a>b)
            swap(a, b);
        pair<int, int> p = {a, b};
        if(set.contains(p)){
            cout<<"2\n";
            return;
        }
        set.insert(p);
    }

    cout<<"3\n";
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
