/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
#include <string>
using std::string;
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) return "0";
        string res="";
        int len=num.size()-k;
        for(char c : num)
        {
            while(k&&res.size()&&res.back()>c)
            {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        res.resize(len);
        int i=0;
        while(i < len-1 && res[i]=='0') i++;
        return res.substr(i);
    }
};
// @lc code=end

