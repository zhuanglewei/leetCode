/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

/*  思路一
单次只移动一位，移动k次
*/
/* 思路二
一次性移动N位,缓存n位
*/
// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int moveCount = k%size;
        if(size <= 1 || moveCount == 0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + moveCount);
        reverse(nums.begin() + moveCount, nums.end());
        
    }
};
// @lc code=end

/*思路一 超时
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size <= 1) return;
        int count = k%size;
        while(count > 0)
        {
            int mid = nums[0];
            for(int i=0; i<size; i++)
            {
                int last = nums[(i+1) % size];
                nums[(i+1) % size] = mid;
                mid = last;
            }
            count--;
        }
    }
*/
/*思路二
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int moveCount = k%size;
        if(size <= 1 || moveCount == 0) return;
        vector<int> midVec(&nums[0], &nums[moveCount]);
        int mid;
        for(int i=0; i<size; i++)
        {
            mid = nums[(i+moveCount)%size];
            nums[(i+moveCount)%size] = midVec[(i+moveCount)%moveCount];
            midVec[(i+moveCount)%moveCount] = mid;
        }
    }
*/