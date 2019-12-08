/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
using std::string;

/*
思路一：
    最长回文字符串，字符串长度为n，可能为最长字符串的是1-n
    理想情况下，也就是n，其次是n-1，依次类推下去
    n的字符串有一个，n-1的为2个，n-2的有3个，依次类推
    判断回文字符串的方式：1.双指针首位对应  
                        2.字符串反转后等于原来的字符串
    此想法超时.....
        // if(s.size()<=1){
        //     return s;
        // }
        // int strSize = s.size();
        // string res = s;
        // bool bReverseString = true;
        // for(int i=0; i<strSize; i++)
        // {
        //     for(int j=0; j<i+1; j++)
        //     {
        //         res = s.substr(j, strSize-i);
        //         bReverseString = true;
        //         for(int k=0; k<(strSize-i)/2; k++){
        //             if(res[k] != res[strSize-i-1-k]){
        //                 bReverseString = false;
        //                 break;
        //             }
        //         }    
        //         if(bReverseString)
        //             return res;
        //     }
        // }
        // return res;

思路二：
    参考网上讨论，以每个字符为字符串的中心，以此判断求出最长回文字符串
    特殊考虑，中心为两个字符的回文字符串
    特殊考虑，字符一样的字符
*/

// @lc code=start
class Solution {
public:
	static string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		int left = 0;
		int midRight = 0;
		int midLeft = 0;
		int midLength = 1;
		int length = 1;
		if (s[0] == s[1])
			length++;
		for (int i = 0; i < s.size(); i++)
		{
			if (i>0 && s[i] == s[i - 1])            //i>0，防止异常
				continue;
			if ((s.size() - i) * 2 <= length)
				break;
			midLeft = i - 1;
            midRight = i + 1;
            midLength = 1;
            while(s[i] == s[midRight])              //字符一样处理
            {
                midRight++;
                midLength++;
            }
			while (midLeft >= 0 && midRight < s.size())
			{
				if (s[midLeft] == s[midRight])
				{
					midLength += 2;
					midLeft--;
					midRight++;
				}	
				else
					break;
			}
			if (midLength > length) {
				length = midLength;
				left = midLeft + 1;
			}
		}
		return s.substr(left, length);
	}
};
// @lc code=end

