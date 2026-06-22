#include <bits/stdc++.h>
using namespace std;
using ll=long long;

class TrieNode {
public:
	TrieNode* children[26];
	int count;

	TrieNode() {
		for (int i = 0; i < 26; ++i) children[i] = nullptr;
		count=0;
	}
};

class Trie {
public:
	TrieNode* root;

	Trie() {
		root = new TrieNode();
	}

	void addWord(const string& word) {
		TrieNode* curr = root;
		for (char c : word) {
		    int idx = c-'a';
			if (!curr->children[idx])
			    curr->children[idx] = new TrieNode();

			curr = curr->children[idx];
			curr->count++;
		}
	}
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie prefixTree;
        int n = words.size();
        vector<int> ans(n);
        unordered_map<string, int> cache;

        for(string& s: words)
            prefixTree.addWord(s);

        for(int i=0; i<n; i++){
            TrieNode* curr = prefixTree.root;
            int score = 0;
            for(char x: words[i]){
                curr = curr->children[x-'a'];
                score += curr->count;
            }
            ans[i] = score;
        }
        return ans;
    }
};
