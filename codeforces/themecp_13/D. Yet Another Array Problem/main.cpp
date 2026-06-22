#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=unsigned long long;

void solve() {
    ll n; cin>>n;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i];

    vector<ll> tries = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for(ll t: tries){
        for(ll i: nums){
            if(gcd(i, t)==1){
                cout<<t<<"\n";
                return;
            }
        }
    }
    cout<<-1<<"\n";
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
