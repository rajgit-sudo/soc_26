#include <bits/stdc++.h>
#include <queue>
#include <utility>
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
    int widthOfBinaryTree(TreeNode* root) {
        ll ans=0;
        queue<pair<TreeNode*, ll>> q;
        q.push(make_pair(root, 0));

        while(!q.empty()){
            int size = q.size();
            ll minLevelIdx = q.front().second;
            ll first, last;
            for(int i=0;i<size; i++){
                ll currIdx = q.front().second - minLevelIdx;
                TreeNode* curr = q.front().first;
                q.pop();

                if(i==0) first = currIdx;
                if(i==size -1) last = currIdx;

                if(curr->left)
                    q.push(make_pair(curr->left, 2*currIdx + 1));
                if(curr->right)
                    q.push(make_pair(curr->right, 2*currIdx + 2));
            }
            ans = max(ans, last - first + 1);
        }
        return (int)(ans);
    }
};

/*
 * 662. Maximum Width of Binary Tree
 * Difficulty: Medium
 * https://leetcode.com/problems/maximum-width-of-binary-tree/
 *
 * ──────────────────────────────────────────────────
 *
 * Given the root of a binary tree, return the maximum width of the
 * given tree.
 *
 * The maximum width of a tree is the maximum width among all levels.
 *
 * The width of one level is defined as the length between the end-nodes
 * (the leftmost and rightmost non-null nodes), where the null nodes
 * between the end-nodes that would be present in a complete binary tree
 * extending down to that level are also counted into the length
 * calculation.
 *
 * It is guaranteed that the answer will in the range of a 32-bit signed
 * integer.
 *
 *
 *
 * Example 1:
 *
 * Input: root = [1,3,2,5,3,null,9]
 * Output: 4
 * Explanation: The maximum width exists in the third level with length
 * 4 (5,3,null,9).
 *
 * Example 2:
 *
 * Input: root = [1,3,2,5,null,null,9,6,null,7]
 * Output: 7
 * Explanation: The maximum width exists in the fourth level with length
 * 7 (6,null,null,null,null,null,7).
 *
 * Example 3:
 *
 * Input: root = [1,3,2,5]
 * Output: 2
 * Explanation: The maximum width exists in the second level with length
 * 2 (3,2).
 *
 *
 *
 * Constraints:
 *
 * 	• The number of nodes in the tree is in the range [1, 3000].
 *
 * 	• -100 <= Node.val <= 100
*/
