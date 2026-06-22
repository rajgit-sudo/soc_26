#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    vector<ll> prefixSum(n-1, 0);
    for(int i=0;i<n-1;i++)
        cin>>prefixSum[i];

    vector<ll> idealElements(n);
    iota(idealElements.begin(), idealElements.end(), 1);

    ll totalSum = prefixSum.back();
    ll expectedSum = (n*(n+1))/2;
    if(expectedSum < totalSum){
        cout<<"NO\n";
        return;
    }
    else if(expectedSum > totalSum){ // final element of prefixSum is totalSum itself
        prefixSum.push_back(expectedSum);

        vector<ll> nums(n);
        nums[0] = prefixSum[0];
        for(int i=1;i<n;i++)
            nums[i] = prefixSum[i]-prefixSum[i-1];
        sort(nums.begin(), nums.end());

        if(nums == idealElements){
            cout<<"YES\n";
            return;
        }else{
            cout<<"NO\n";
            return;
        }
    }else{ //missing element is smwhere in the middle
        vector<bool> freq(n, false);
        vector<int> differenceArray;
        differenceArray.push_back(prefixSum.front());
        if(prefixSum.front()-1 <= n)
            freq[prefixSum.front()-1] = true;


        for(int i=1;i<int(prefixSum.size());i++){
            ll difference = prefixSum[i] - prefixSum[i-1] -1;
            if(difference<=n)
                freq[difference] = true;
            differenceArray.push_back(difference+1);
        }

        int currSum=0;
        for(int i=0;i<n;i++){
            if(freq[i]==false)
                currSum+=i+1;
        }

        sort(differenceArray.begin(), differenceArray.end());
        if(binary_search(differenceArray.begin(), differenceArray.end(), currSum)){
            cout<<"YES\n";
            return;
        }else{
            cout<<"NO\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in4.txt", "r", stdin);
    // freopen("res4.txt", "w", stdout);


    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
