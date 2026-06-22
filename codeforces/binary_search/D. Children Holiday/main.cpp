#include <bits/stdc++.h>
#include <numeric>
#include <pthread.h>
#include <vector>
using namespace std;
using ll=long long;

struct Balloon{
    ll inflationTime;
    ll balloonLimit;
    ll restTime;

    Balloon(ll i, ll b, ll r){
        inflationTime = i;
        balloonLimit = b;
        restTime = r;
    }
};

ll balloonsByEmployee(Balloon& employee, ll timeLimit){
    ll ans=0;
    ll cycleLength = employee.balloonLimit*employee.inflationTime + employee.restTime;
    ans += (timeLimit/cycleLength) * employee.balloonLimit;

    ll timeLeft = timeLimit%cycleLength;
    ans += min(employee.balloonLimit, timeLeft/employee.inflationTime);
    return ans;
}

void solve() {
    ll n, m; cin>>m>>n;
    vector<Balloon> nums;
    for(int i=0;i<n;i++){
        ll a, b, c; cin>>a>>b>>c;
        nums.push_back(Balloon(a,b,c));
    }

    auto valid = [&](ll timeLimit){
        ll ans=0;
        for(int i=0;i<n;i++){
            ans += balloonsByEmployee(nums[i], timeLimit);
            if(ans>=m) return true;
        }
        return ans>=m;
    };

    ll low = 0, high = 1e9, mid;
    ll ans = high;
    while(low<=high){
        mid = midpoint(low, high);
        if(valid(mid)){
            ans = min(ans, mid);
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<ans<<"\n";

    vector<ll> result(n);
    for(int i=0;i<n;i++){
        ll canMake = balloonsByEmployee(nums[i], ans);
        result[i] = min(canMake, m);
        m-=result[i];
    }

    for(ll i: result)
        cout<<i<<" ";
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
