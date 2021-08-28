/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:

    int getCount(string &s, int &index) {
        bool add = true;
        int res = 0;
        int mid = 0;
        for (; index < s.size(); index++) {
            if (s[index] == ' ') {
                continue;
            } else if (s[index] == '(') {
                index++;
                mid = getCount(s, index);
                res = (add ? mid : -mid) + res;
                mid = 0;
            } else if (s[index] == ')') {
                res = (add ? mid : -mid) + res;
                return res;
            } else if (s[index] == '+' || s[index] == '-') {
                res = (add ? mid : -mid) + res;
                add = (s[index] == '+');
                mid = 0;
            } else {
                mid = mid * 10 + (s[index] - '0');
            }
        }
        res = (add ? mid : -mid) + res;
        return res;
    }

    int calculate(string s) {
        int index = 0;
        int res = getCount(s, index);
        return res;
    }
};
// @lc code=end

