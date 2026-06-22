#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);

        for(const vector<int>& row: nums){
            inDegree[row[0]]++;
            graph[row[1]].push_back(row[0]);
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)
                q.push(i);
        }

        vector<int> topsort;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topsort.push_back(node);

            for(int nextNode: graph[node]){
                inDegree[nextNode]--;

                if(inDegree[nextNode]==0)
                    q.push(nextNode);
            }
        }

        return int(topsort.size()) == n;
    }
};
