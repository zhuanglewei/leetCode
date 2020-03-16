/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include<vector>
using std::vector;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return nums.size();
        }
        int res = 1;
        int state = 0;
        int lastCount = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            switch (state)
            {
            case 0: 
                if(nums[i] == lastCount)
                {
                    break;  
                }   
                else{
                    state = nums[i] > lastCount ? 1 : -1;
                    res++;
                }
                break;
            case 1:
                if(nums[i] < lastCount)
                {
                    res++;
                    state = -1;
                }
                break;
            case -1:
                if(nums[i] > lastCount) 
                {
                    res++;
                    state = 1;
                }
            default:
                break;
            }
            lastCount = nums[i];
        }
        return res;
    }
};
// @lc code=end

