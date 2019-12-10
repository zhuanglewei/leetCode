/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (42.15%)
 * Likes:    304
 * Dislikes: 0
 * Total Accepted:    59.2K
 * Total Submissions: 140.3K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
/*
    思路：
        参考三数之和，将数组进行排序，再利用双指针方式，依次找到最合适的值
        如例子排序后为 -4，-1， 1， 2 ，依次取首值，剩下部分取首位指针
*/
#include<vector>
#include<algorithm>
using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int res = nums[0] + nums[1] + nums[2];
		int midRes = res;
		int gap = abs(res - target);
		int midGap, left, right;
		for (int i = 0; i < nums.size()-2; i++) {
			left = i + 1;
			right = nums.size() - 1;
			while (left != right)
			{
				midRes = nums[i] + nums[left] + nums[right];
				midGap = abs(midRes - target);
				if (midGap < gap)
				{
					res = midRes;
					gap = midGap;
				}
				if (midRes > target) {
					right--;
				}
				else if (midRes < target) {
					left++;
				}
				else {
					return target;
				}
			}
			if (nums[i]+nums[i+1]+nums[i+2] > target)
				break;
		}

		return res;
    }
};
// @lc code=end

