#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    TreeNode* building(span<int> preorder, span<int> inorder){
        if(preorder.empty())
            return nullptr;

        TreeNode* root = new TreeNode(preorder.front());

        int mid = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder.front()));
        root->left = building(preorder.subspan(1, mid), inorder.first(mid));
        root->right = building(preorder.subspan(mid+1), inorder.subspan(mid+1));

        return root;
    }

    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        span<int> preorder(p), inorder(i);
        TreeNode* root = building(preorder, inorder);
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

