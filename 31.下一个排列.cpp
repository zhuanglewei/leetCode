/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.29%)
 * Likes:    332
 * Dislikes: 0
 * Total Accepted:    33.6K
 * Total Submissions: 104K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int id1=-1,id2;
        int submin;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                id1=i-1;
                id2=i;
                break;
            } 
        }
        if(id1==-1) sort(nums.begin(),nums.end());
        else{
            submin=nums[id1+1];
            for(int i=id1+1;i<nums.size();i++){
                if(nums[i]>nums[id1]&&nums[i]<submin) {
                    submin=nums[i];
                    id2=i;
                }
            }
            swap(nums[id1],nums[id2]);
            sort(nums.begin()+id1+1,nums.end());
        }
    }
};
// @lc code=end

