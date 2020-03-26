/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
// @lc code=end

// 神奇解法 100%
// 82 - 8*9 = 10 - 1*9 = 1;
// 减去的值均为9的倍数
// 即一般答案为 num%9;
// 特殊情况 num = 9;
//
// int addDigits(int num) {
//     return 1 + (num - 1) % 9;
// }

// 正常思维 70%
// 
// int addDigits(int num) {
//     int res = num;
//     while(res >= 10)
//     {
//         int mid = res;
//         res = 0;
//         while(mid > 0)
//         {
//             res += mid%10;
//             mid /= 10;
//         }
//     }
//     return res;
// }