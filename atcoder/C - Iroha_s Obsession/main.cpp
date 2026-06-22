#include <bits/stdc++.h>
#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    unordered_set<int> disAllowed;
    for(int i=0;i<k;i++){
        int a; cin>>a;
        disAllowed.insert(a);
    }

    int temp = n;
    vector<int> digits;
    while(temp){
        int digit = temp%10;
        digits.push_back(digit);
        temp/=10;
    }

    reverse(digits.begin(), digits.end());

    bool flag = false;
    for(int& i: digits){
        if(disAllowed.contains(i)){
            if(!flag){
                while(disAllowed.contains(i)){
                    i++;
                }
            }
            else{
                while(i>0 && disAllowed.contains(i))
                    i--;

                if(i==0 && disAllowed.contains(i)){
                    while(disAllowed.contains(i))
                        i++;
                }
            }
        }
    }

    for(int i: digits)
        cout<<i;

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
