/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int reach = 0;
        int nextreach = nums[0];
        int step = 0;
        for(int i = 0;i<nums.size();i++){
            nextreach = i+nums[i] > nextreach ? i+nums[i] : nextreach;
            if(nextreach >= nums.size()-1) return (step+1);
            if(i == reach){
                step++;
                reach = nextreach;
            }
        }
        return step;
    }
};
// @lc code=end

