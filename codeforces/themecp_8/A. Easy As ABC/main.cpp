#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <queue>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n = 3;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    }

    vector<string> ans;
    vector<pair<int, int>> neighbours = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string curr="";
            curr.push_back(grid[i][j]);
            for (const pair<int, int>& neighbour : neighbours) {
                int r = i + neighbour.first;
                int c = j + neighbour.second;

                if (r<0 || r>=n || c<0 || c>=n) continue;
                curr.push_back(grid[r][c]);

                for (const pair<int, int>& neighbour : neighbours) {
                    int rr = r + neighbour.first;
                    int cc = c + neighbour.second;

                    if (rr<0 || rr>=n || cc<0 || cc>=n) continue;
                    if(rr==i && cc==j) continue;

                    curr.push_back(grid[rr][cc]);
                    ans.push_back(curr);
                    curr.pop_back();
                }
                curr.pop_back();
            }
        }
    }
    cout<<*min_element(ans.begin(), ans.end())<<"\n";
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
