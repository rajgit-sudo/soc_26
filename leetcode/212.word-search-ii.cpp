#include <bits/stdc++.h>
using namespace std;
using ll=long long;

class TrieNode {
public:
	TrieNode* children[26];
	bool isWord;

	TrieNode() {
		for (int i = 0; i < 26; ++i) children[i] = nullptr;
		isWord = false;
	}

	void addWord(const string& word) {
		TrieNode* curr = this;
		for (char c : word) {
			if (!curr->children[c - 'a']) {
				curr->children[c - 'a'] = new TrieNode();
			}
			curr = curr->children[c - 'a'];
		}
		curr->isWord = true;
	}
};

class Solution {
public:
    int n, m;
    TrieNode* root = new TrieNode();
    vector<string> ans;
    vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, TrieNode* curr, int i, int j){
        if(curr->isWord){
            ans.push_back(word);
            curr->isWord = false;
        }

        for (const pair<int, int>& neighbour : neighbours) {
            int r = i + neighbour.first;
            int c = j + neighbour.second;

            if (r<0 || r>=n || c<0 || c>=m) continue;
            if(visited[r][c]) continue;
            if(curr->children[board[r][c]-'a']==nullptr) continue;

            visited[r][c] = true;
            word.push_back(board[r][c]);
            dfs(board, visited, word, curr->children[board[r][c]-'a'], r, c);
            visited[r][c] = false;
            word.pop_back();
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = (board[0]).size();
        for(string& s: words)
            root->addWord(s);

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                TrieNode* startNode = root->children[board[i][j]-'a'];
                if(startNode!=nullptr){
                    visited[i][j] = true;
                    string word = string(1, board[i][j]);
                    dfs(board, visited, word, startNode, i, j);
                    visited[i][j] = false;
                }
            }
        }
        return ans;
    }
};
