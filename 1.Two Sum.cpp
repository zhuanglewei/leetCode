/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (46.63%)
 * Likes:    6365
 * Dislikes: 0
 * Total Accepted:    568K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>  IndexMap;
        vector<int> result;
        int i=0;
        for(int n : nums)
        {
            IndexMap[n] = i++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = IndexMap.find(target-nums[i]);
            if (it != IndexMap.end() && it->second != i)//防止数字标识相同，例如6=3+3
            {
                result.push_back(i);
                result.push_back(it->second);
                return result;
            } 
        }
        return result;
        
    }
};
//使用unordered_map做哈希表查找，时间复杂度为O(n)
//注意的点是，目标值可能为同一数值的倍数，例如6=3+3,不应该返回俩个ID相同的结果
//auto自动推导
//for的新型使用
//迭代器的使用

