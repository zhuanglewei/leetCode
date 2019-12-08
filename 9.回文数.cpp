/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
/*
 *所谓的回文数，就是首尾倒着来是一样的数字
 *那么负数一定不是回文数
 *常规思考方式，转换为string，进行回文比较，需要转换操作
 *直接进行int类型的回文比较，即每次各取首位进行比较，比较完则移除首位俩位
 *
 *边界条件为 10012，这种情况下移除首位俩位时，将会发生数值转换为1，但比较的值应该是0与1
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int nCount = 1;
        int nDigit = 1;
        int MidNums = x;
        while(MidNums >= 10)        //获取数值为多少位数
        {
            MidNums = MidNums/10;
            nCount++;
            nDigit *= 10;
        }    
        int nRight,nleft;
        while(nCount > 1)           //根据数值位数进行判断
        {
            nRight = x%10;
            if(x >= nDigit)
            {
                nleft = x/nDigit;
                x = x - nleft*nDigit;   
            }    
            else{
                nleft = 0;
            }
            if(nleft != nRight)
                return false;
            x /= 10;
            nDigit /= 100;
            nCount -= 2;
        }
        return  true;
    }
};
// @lc code=end

