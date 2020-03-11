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
        if(num.size() <= k)
        {
            return "0";
        }
        
        for(int i = 0; i<k; i++)
        {
            int mid = i+1;
            while(mid < num.size() && num[i] == num[mid])
            {
                mid++;
            }
            if(num[i] < num[mid])
            {
                int right = mid;
                while(right < num.size() && num[mid] == num[right])
                {
                    right++;
                }
                if(num[mid] < num[right])
                {
                    num[right] = num[mid];
                    num[mid] = num[i];
                }
                else
                {
                    num[mid] = num[i];
                }
            }
        }
        while(num[k] == '0' && k < num.size()-1)
        {
            k++;
        }
        return num.substr(k);
    }
};
// @lc code=end

