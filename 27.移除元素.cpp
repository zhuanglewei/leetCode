/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 *
 * https://leetcode-cn.com/problems/remove-element/description/
 *
 * algorithms
 * Easy (56.64%)
 * Likes:    433
 * Dislikes: 0
 * Total Accepted:    113.5K
 * Total Submissions: 200.3K
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
 * 
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 * 
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 * 
 * 示例 1:
 * 
 * 给定 nums = [3,2,2,3], val = 3,
 * 
 * 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
 * 
 * 你不需要考虑数组中超出新长度后面的元素。
 * 
 * 
 * 示例 2:
 * 
 * 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
 * 
 * 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
 * 
 * 注意这五个元素可为任意顺序。
 * 
 * 你不需要考虑数组中超出新长度后面的元素。
 * 
 * 
 * 说明:
 * 
 * 为什么返回数值是整数，但输出的答案是数组呢?
 * 
 * 请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 * 
 * 你可以想象内部操作如下:
 * 
 * // nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
 * int len = removeElement(nums, val);
 * 
 * // 在函数里修改输入数组对于调用者是可见的。
 * // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 * 
 */

// @lc code=start
/*
思路一：
    遍历整个数组，记录着相同的值的数目，并将相同值的数目，并将后面的数字向前移动整个数目
        int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                res++;
                continue;
            }
            nums[i-res] = nums[i];
        }
        return nums.size()-res;
    }
思路二：
    明显思路一中，将一部分不需要移动的值也移动了，此时的解决方法，双指针法，一个尾部，一个头部
    头部的指针发现需要移动的数据时，将尾部数据移动至头部即可
    然后边界条件就多了一堆。。。
*/

#include<vector>
using std::vector;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res=nums.size();
        if(nums.size() == 0)
            return 0;
        int left = 0;
        int right = nums.size()-1;
        while(right >=0 && nums[right] == val){
            right--;
            res--;
        }
        if(right<0)
            return 0;
        while(left <= right){
            if(nums[left] == val){
                res--;
                nums[left++] = nums[right--];
                while(nums[right] == val)
                {
                    right--;
                    res--;
                } 
            }
            else
                left++;
        }
        return res;
    }
};
// @lc code=end

