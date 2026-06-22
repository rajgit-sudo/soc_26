#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool isPalindrome(string& s, int i, int k){
    int j = i + k-1;
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++; j--;
    }
    return true;
}

bool containsPalindrome(string& s, int k){
    int n = s.size();
    for(int i=0; i<=n-k; i++){
        if(isPalindrome(s, i, k))
            return true;
    }
    return false;
}

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    sort(s.begin(), s.end());
    ll ans=0;
    do {
        if(!containsPalindrome(s, k))
            ans++;
    }while(next_permutation(s.begin(), s.end()));

    cout<<ans;
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
