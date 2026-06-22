#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using ll=long long;
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
// struct TreeNode {
// 	int val;
// 	TreeNode* left;
// 	TreeNode* right;

// 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
// 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// 	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
            return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front(); q.pop();
                level.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(level.back());
        }
        return ans;
    }
};

/*
 * 199. Binary Tree Right Side View
 * Difficulty: Medium
 * https://leetcode.com/problems/binary-tree-right-side-view/
 *
 * ──────────────────────────────────────────────────
 *
 * Given the root of a binary tree, imagine yourself standing on the
 * right side of it, return the values of the nodes you can see ordered
 * from top to bottom.
 *
 *
 *
 * Example 1:
 *
 * Input: root = [1,2,3,null,5,null,4]
 *
 * Output: [1,3,4]
 *
 * Explanation:
 *
 * Example 2:
 *
 * Input: root = [1,2,3,4,null,null,null,5]
 *
 * Output: [1,3,4,5]
 *
 * Explanation:
 *
 * Example 3:
 *
 * Input: root = [1,null,3]
 *
 * Output: [1,3]
 *
 * Example 4:
 *
 * Input: root = []
 *
 * Output: []
 *
 *
 *
 * Constraints:
 *
 * 	• The number of nodes in the tree is in the range [0, 100].
 *
 * 	• -100 <= Node.val <= 100
*/
