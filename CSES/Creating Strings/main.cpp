#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    string s; cin>>s;
    sort(s.begin(), s.end());

    vector<string> ans;
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout<<ans.size()<<"\n";
    for(string s: ans)
        cout<<s<<"\n";
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
