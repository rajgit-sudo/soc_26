#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    int neg=0, zero=0;
    ll ans=0;
    for (int i=0; i<n; i++){
        int a; cin>>a;
        nums[i] = abs(a);
        ans+=nums[i];
        if(a<0)
            neg++;
        else if(a==0)
            zero++;
    }

    if(neg%2==0 || zero>0){
        cout<<ans<<"\n";
    }else{
        cout<<ans-2*(*min_element(nums.begin(), nums.end()))<<"\n";
    }
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
