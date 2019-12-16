/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (38.25%)
 * Likes:    262
 * Dislikes: 0
 * Total Accepted:    49.1K
 * Total Submissions: 128.2K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

// @lc code=start
/*
思路：
二分查找法，再加个双指针找个边界值
*/
#include<vector>
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
        int mid = (left + right) / 2;

        if(right == -1 || nums[right] < target || nums[left] > target){
            return {-1,-1};
        }
        else if(right == 0){
            if(nums[0] != target)
                return {-1,-1};
            else
                return {0,0};
        }
            
		bool find = false;
		while (left < right) {      //二分查找法
			if (nums[mid] == target) {
				find = true;
				break;
			}
			else if (nums[mid] < target) {
				left = mid;
				mid = (left + right) / 2;
				if (mid == left) {
					if(nums[right] != target)
                        break;
                    else 
                    {
                        mid = right;
                        find = true;
                        break;
                    }
				}	
			}
			else{
				right = mid;
				mid = (left + right) / 2;
			}
		}

		if (find) {
			while (nums[left] != target)
				left++;
            while(nums[right] != target)
                right--;
            return vector<int>{left, right};
		}
		return {-1, -1};
    }
};
// @lc code=end

