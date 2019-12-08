/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long nMin = 1;
        long nMax = 1;
        nMax = nMax<<32 - 1;
        nMin = -(nMin<<31);
        if(x == nMin)
            return 0;
        long ans = 0;
        int flag = 1;
        
        if(x < 0)
        {
            flag = -1;
            x = -x;
        }
        while(x)
        {
            long temp;
            if((temp = ans * 10 + x % 10) > nMax)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans * flag;
    }
};
// @lc code=end

