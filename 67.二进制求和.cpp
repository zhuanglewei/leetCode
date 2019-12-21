/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (51.52%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    52.8K
 * Total Submissions: 102.4K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
#include<string>
#include<algorithm>

using std::string;
class Solution {
public:
    string addBinary(string a, string b) {
        string s;
		s.reserve(a.size() + b.size());
		int c = 0, i = a.size() - 1, j = b.size() - 1;
		while(i >= 0 || j >= 0 || c == 1)
		{
			c += i >= 0 ? a[i--] - '0' : 0;
			c += j >= 0 ? b[j--] - '0' : 0;
			s.push_back((c & 1) + '0');
			c >>= 1;
		}
		reverse(s.begin(), s.end());
		return s;
    }
};
// @lc code=end

