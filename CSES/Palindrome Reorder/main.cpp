#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    string s; cin>>s;
    vector<int> freq(26, 0);
    for(char x: s)
        freq[x-'A']++;

    bool odd = false;
    char oddChar;
    int oddCount = 1;
    for(int i=0;i<26;i++){
        if(freq[i]%2==1 && !odd){
            odd = true;
            oddChar = (i+'A');
            oddCount = freq[i];
        }else if(freq[i]%2==1 && odd){
            cout<<"NO SOLUTION";
            return;
        }
    }

    string ans="";
    for(int i=0;i<26;i++){
        if(freq[i]%2==0){
            ans.append(string(freq[i]/2, 'A'+i));
        }
    }
    string reversed(ans.rbegin(), ans.rend());
    if(odd){
        ans = ans + string(oddCount, oddChar) + reversed;
    }else{
        ans = ans + reversed;
    }
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
