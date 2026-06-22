#include <bits/stdc++.h>
using namespace std;
using ll=long long;


const int N = 8;
vector<bool> cols(N, false);
set<int> mainDiagonal, antiDiagonal;
void backtrack(vector<string>& board, int& ans, int queensRemaining, int r=0){
    if(queensRemaining==0){
        // cout<<"HI\n";
        ans++;
        return;
    }
    if(r>=N)
        return;

    for(int c=0;c<N;c++){
        if(cols[c]) continue;
        if(mainDiagonal.find(r-c)!=mainDiagonal.end()) continue;
        if(antiDiagonal.find(r+c)!=antiDiagonal.end()) continue;
        if(board[r][c]=='*') continue;

        cols[c]=true;
        mainDiagonal.insert(r-c);
        antiDiagonal.insert(r+c);
        backtrack(board, ans, queensRemaining-1, r+1);
        cols[c]=false;
        mainDiagonal.erase(r-c);
        antiDiagonal.erase(r+c);
    }
}

void solve() {
    vector<string> board(N);
    for(int i=0;i<N;i++)
        cin>>board[i];

    int ans=0;
    backtrack(board, ans, N);
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
