/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
 
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        dfs(root);
        sort(nums.begin(),nums.end());
    }
    
    /** @return the next smallest number */
    int next() {
        return nums[loca++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return loca < nums.size();
    }

private:

    void dfs(const TreeNode * root) {
        if(root != nullptr) {
            nums.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }
    }
    vector<int> nums;
    int loca = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

