/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.12%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    44.6K
 * Total Submissions: 123K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
/*
思路一：
    类似地从两数之和思考，构建一个两数之和的列表，再根据两数之和算出四数之和
    步骤一：构建两数之和的散列表
    步骤二：遍历散列表，从值一求出值二
           值一与值二都有多种可能，再进行配对
           四元组存在相同的可能     
    边界条件判断复杂，散列表消耗资源大，放弃
        vector<vector<int>> res;
        unordered_map<int,vector<int>> twoSumMap;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                int twoNum = nums[i]+nums[j];
                auto it = twoSumMap.find(twoNum);
                if(it!=twoSumMap.end()){
                    twoSumMap[twoNum].push_back(i);
                    twoSumMap[twoNum].push_back(j);
                }
                else 
                    twoSumMap[twoNum] = vector<int>{i,j};
            }
        }
        
        for(auto it = twoSumMap.begin(); it!=twoSumMap.end(); it++){
            auto item = twoSumMap.find(target - it->first);
            if(item != twoSumMap.end())
            {
                for(int i=0; i<it->second.size()/2; i++){
                    for(int j=0; j<item->second.size()/2; j++){
                        if(item->second[j] != it->second[i] && item->second[j+1] != it->second[i+1])
                        {
                        }
                }
                }

            }
        }

        return res;    
思路二：
    类似于三数之和的两个指针夹逼求值，换为两个定值，剩下两个指针仍旧夹逼求职操作
        不能存在相同的四元组（有点恶心）
*/

#include <unordered_map>
#include <vector>
#include <algorithm>
using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
        if(nums.size() < 4)
            return res;
		sort(nums.begin(), nums.end());
		int left, right;
		for (int i = 0; i < nums.size() - 3; i++) {
            if(i> 0 && nums[i] == nums[i-1])
                continue;
			for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j>i+1 && nums[j] == nums[j-1])
					continue;
				left = j + 1;
				right = nums.size() - 1;
				if (nums[i] + nums[j] + nums[left] + nums[left + 1] > target) {
					break;
				}
				while (left < right) {
					if (nums[left] == nums[left - 1] && left != j + 1) {
						left++;
						continue;
					}
					if (right != nums.size()-1 && nums[right] == nums[right + 1]) {
						right--;
						continue;
					}
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						left++;
						right--;
					}
					else if (sum < target) {
						left++;
					}
					else {
						right--;
					}
				}
			}
		}
		return res;
	}
};
// @lc code=end

