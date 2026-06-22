#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MULTIPLIER = 9;

void solve() {
    int n; cin>>n;
    int ans = 0;
    int digits = 0;
    int temp = n;
    while(temp){
        digits++;
        temp/=10;
    }
    ans = (MULTIPLIER) * (digits-1);

    int minRange = 1, maxRange = 9;
    for(int i=1; i<digits; i++){
        minRange = minRange*10 + 1;
        maxRange = maxRange*10 + 9;
    }

    for(int i=minRange; i<=maxRange; i+=minRange){
        if(n>=i)
            ans++;
        else
            break;
    }
    cout<<ans<<"\n";
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
