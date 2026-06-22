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
			if (!curr->children[c - 'a']) {
				curr->children[c - 'a'] = new TrieNode();
			}
			curr = curr->children[c - 'a'];
		}
		curr->isWord = true;
	}

	bool search(const string& word) {
		TrieNode* curr = root;
		for (char c : word) {
			if (!curr->children[c - 'a']) return false;
			curr = curr->children[c - 'a'];
		}
		return curr->isWord;
	}

	bool startsWith(const string& prefix) {
		TrieNode* curr = root;
		for (char c : prefix) {
			if (!curr->children[c - 'a']) return false;
			curr = curr->children[c - 'a'];
		}
		return true;
	}
};

class Solution {
public:
    int n;
    vector<int> cache;
    Trie prefixTree;

    int recurse(string& s, int idx){
        if(cache[idx]!=-1)
            return cache[idx];

        int ans = 1 + recurse(s, idx+1);
        string currWord = "";
        for(int j=idx; j<n; j++){
            currWord.push_back(s[j]);
            if(!prefixTree.startsWith(currWord))
                break;
            if(prefixTree.search(currWord)){
                ans = min(ans, recurse(s, j+1));
            }
        }
        cache[idx] = ans;
        return ans;
    }

    int minExtraChar(string s, vector<string>& inputDictionary) {
        n = s.size();
        for(string& s: inputDictionary)
            prefixTree.addWord(s);

        cache.assign(n+1, -1);
        cache[n] = 0;
        return recurse(s, 0);
    }
};
