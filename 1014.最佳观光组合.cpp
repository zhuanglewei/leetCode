/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
// 
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0, mid=0,leftIndex = 0;
        for(int i=1; i<A.size(); i++)
        {
            mid = A[i] + A[leftIndex] + leftIndex - i;
            if(mid > res)
                res = mid;
            if(A[i] > A[leftIndex] + leftIndex - i)
            {
                leftIndex = i;
            }
        }
        return res;
    }
};
// @lc code=end

