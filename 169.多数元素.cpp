/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 摩尔投票法
        int res=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0) {
                res=nums[i];
                cnt++;
            }
            else{
                res==nums[i]?cnt++:cnt--;
            }
        }
        return res;
    }
};
// @lc code=end

