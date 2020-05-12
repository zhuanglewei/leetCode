/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */
// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = 0,res=0, size = nums.size();
        sort(nums.begin(), nums.end());
        
        if(size % 2 == 0)
        {
            mid = (nums[size / 2] + nums[size/2 - 1])/2;
        }
        else
        {
            mid = nums[size / 2];
        }
        for(auto i: nums)
        {
            res += abs(mid - i);
        }
        return res;
    }
};
// @lc code=end

//中位数接近问题