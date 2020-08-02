/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int res = 1;
        vector<TreeNode*> vec;
        vec.push_back(root);
        int loca = 0;
        int next = vec.size();
        while (vec[loca]->left != nullptr || vec[loca]->right != nullptr) {
            if (vec[loca]->left != nullptr) {
                vec.push_back(vec[loca]->left);
            }
            if (vec[loca]->right != nullptr) {
                vec.push_back(vec[loca]->right);
            }
            loca++;
            if (loca == next) {
                next = vec.size();
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

