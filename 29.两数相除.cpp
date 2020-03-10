/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

#include <math.h>

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        if(divisor == 0)
            return res;
        if(divisor == 1)
            return dividend;
        bool bNegative = true;
        bool bRemainder = false;
        if(dividend == 0x80000000)
        {
            dividend = 0x7fffffff;
            bRemainder = true;
            bNegative = !bNegative;
        }
        if(divisor == 0x80000000){
            return bRemainder ? 1 : 0;
        }
        if((divisor == -1 && bRemainder) ||(divisor==1 && dividend == 0x7fffffff))
        {
            return 0x7fffffff;
        }
        if(dividend < 0)
        {
            dividend = -dividend;
            bNegative = !bNegative;
        }
        if(divisor < 0)
        {
            divisor = -divisor;
            bNegative = !bNegative;
        }
        if(dividend >= divisor){
            dividend -= divisor;
            res += 1;
        }
        int count = 1;
        int mid = divisor;
        while(dividend >= divisor){
            if(dividend >= mid)
            {
                dividend -= mid;
                res += count;
                if(dividend > mid)
                {
                    mid = mid << 1;
                    count = count << 1;
                }
            }
            else
            {
                mid = mid >> 1;
                count = count >> 1;
            }
        }
        if(divisor - dividend == 1 && bRemainder)
            res++;
        return bNegative ? res : -res;
    }
};
// @lc code=end

