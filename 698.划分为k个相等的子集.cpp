/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
#include <map>

class Solution {
public:
    int n, target = 0;
    bool dfs(int idx, vector<int> &sum, vector<int>& nums) {
        if(idx == -1) {//从大到小，成功所有数字都放入框内
            return true;
        }
        for(int i = 0; i < n; i++) {
            if(nums[idx] + sum[i] <= target) {//剪枝
                sum[i] += nums[idx];
                if(dfs(idx - 1, sum, nums)) return true;
                sum[i] -= nums[idx];
            }
            while(i + 1 < n && sum[i + 1] == sum[i]) i++; //关键剪枝！跳过相同情况
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = k;
        for(int i = 0; i < nums.size(); i++) target += nums[i];
        if(target % k != 0) return false;
        vector<int> sum(nums.size(), 0);
        target /= k;
        sort(nums.begin(), nums.end());
        return dfs(nums.size() - 1, sum, nums);
        
    }
};
// @lc code=end

