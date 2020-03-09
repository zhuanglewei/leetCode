/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() <= 1){
           return;
        }
        // 遍历一次的做法
        int red = 0;
        int white = 0;
        for(int i=0; i<nums.size(); i++){
            switch (nums[i])
            {
            case 0:
                nums[i] = nums[red];
                nums[red++] = 0;
                if(nums[i] == 1 && nums[i-1] == 2)
                {
                    nums[red+white-1] = 1;
                    nums[i] = 2; 
                }
                break;
             case 1:
                if(i > 0 && nums[i-1] == 2)
                {
                    nums[red+white++] = 1;
                    nums[i] = 2; 
                }
                else
                {
                    white++;
                }
                
                break;
            case 2:
                break;
            default:
                break;
            }
        }


        // 遍历两次的做法
        // int red = 0;
        // int white = 0;
        // int blue = 0;
        // for(int i: nums)
        // {
        //     switch(i){
        //         case 0:
        //             red++;
        //             break;
        //         case 1:
        //             white++;
        //             break;
        //         case 2:
        //             blue++;
        //             break;
        //         default:
        //             break;
        //     }    
        // }
        // for(int i=0; i<red; i++){
        //     nums[i] = 0;
        // }
        // for(int i=red; i<red+white; i++){
        //     nums[i] = 1;
        // }
        // for(int i=red+white; i<nums.size(); i++){
        //     nums[i] = 2;
        // }
    }
};
// @lc code=end

