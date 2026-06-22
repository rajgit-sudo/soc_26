#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> dp(n+1, 0);
    for(int i=1; i<=9; i++)
        dp[i] = 1;

    auto maxDigit = [](int n){
        int maxDigit = 0;
        while(n){
            maxDigit = max(maxDigit, n%10);
            n/=10;
        }
        return maxDigit;
    };

    for(int i=10; i<=n; i++){
        dp[i] = 1 + dp[i-maxDigit(i)];
    }
    cout<<dp[n];
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
