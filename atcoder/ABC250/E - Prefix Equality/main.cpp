#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    unordered_map<int, unordered_set<int>> set1, set2;

    unordered_set<int> set;
    for(int i=0;i<n;i++){
        cin>>a[i];
        set.insert(a[i]);
        set1[i+1] = set;
    }
    set.clear();
    for(int i=0;i<n;i++){
        cin>>b[i];
        set.insert(b[i]);
        set2[i+1] = set;
    }

    int q; cin>>q;
    for(int i=0;i<q;i++){
        int l, r; cin>>l>>r;

        if(set1[l] == set2[r])
            cout<<"Yes\n";
        else
            cout<<"No\n";
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
