#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int ans=0;
vector<pair<int, int>> moves;

void hanoi(int n, int start, int end){
    if(n==1){
        moves.push_back({start, end});
        ans++;
        return;
    }
    int other = 6 - start - end;
    hanoi(n-1, start, other);
    hanoi(1, start, end);
    hanoi(n-1, other, end);
}

void solve() {
    int n; cin>>n;
    int start = 1;
    int end = 3;
    hanoi(n, start, end);
    cout<<ans<<"\n";
    for(auto p: moves)
        cout<<p.first<<" "<<p.second<<"\n";
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
