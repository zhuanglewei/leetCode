/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 *
 * https://leetcode-cn.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (37.09%)
 * Likes:    392
 * Dislikes: 0
 * Total Accepted:    47.9K
 * Total Submissions: 129.1K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 判断你是否能够到达最后一个位置。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: true
 * 解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,1,0,4]
 * 输出: false
 * 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 * 
 * 
 */

// @lc code=start
/*
思路：
递归算法解决，应该很好解决
果不其然，超时了，通过了72/75的用例，对递归判断进行优化
    bool canJump(vector<int>& nums) {
        return func(nums, 0);
    }
    bool func(vector<int> nums, int location){
        if(location == nums.size()-1 || nums[location] + location >= nums.size()-1){
            return true;
        }
        else if(nums[location] == 0){
            return false;
        }
        for(int i=nums[location]; i>0; i--){
            if(func(nums, location + i)){
                return true;
            }
        }
        return false;
优化后如下，变成通过率73/75，一堆个数为1的数，递归不断压栈，性能果然不行，还是超时，但优化的逻辑
已经不需要递归，也可以轻松写出代码了
        for(int i=nums[location]-1; i>0; i--){
            temp = i + nums[location + i];
            if(max < temp){
                max = temp;
                nextLocation = i + location;
            }
        }
        return func(nums, nextLocation);
    }
果然非递归就可以通过了
*/
#include<vector>
using std::vector;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
        if(nums.size() == 1)
            return true;
        int location = 0;
        while(nums[location] != 0){
            if(location == nums.size()-1 || nums[location] + location >= nums.size()-1){
                return true;
            }
            int max = nums[location] + nums[location + nums[location]];
            int temp = 0;
            int nextLocation = location + nums[location];
            for(int i=nums[location]-1; i>0; i--){
                temp = i + nums[location + i];
                if(max < temp){
                    max = temp;
                    nextLocation = i + location;
                }
            }
            location = nextLocation;
        }
        return false;
        */

        //网上神仙写法
        //可以到达最后一个节点，也就是可以到达所有节点，判断从每个点能到达的最远的点，就可以得出答案
       	int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) return false;
            k = max(k, i + nums[i]);
            if(k >= nums.size()-1)      //增加判断，则只要能达到最后一个节点，即可退出
                break;
        }
        return true;
    }
};
// @lc code=end

