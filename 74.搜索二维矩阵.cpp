/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// 二分查找法

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        int x = matrix[0].size(), y = matrix.size();

        int left = 0, right = x*y-1;
        int mid = right / 2;
        if(target > matrix[right/x][right%x] || target < matrix[left/x][left%x])
        {
            return false;
        }
        else if(target == matrix[right/x][right%x] || target == matrix[left/x][left%x])
        {
            return true;
        }
        while(matrix[mid/x][mid%x] != target && left != right && right > left+1)
        {
            if(matrix[mid/x][mid%x] < target)
            {
                left = mid;   
            }
            else
            {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        if(matrix[mid/x][mid%x] != target)
        {
            return false;
        }
        else{
            return true;
        }
    }
};
// @lc code=end

