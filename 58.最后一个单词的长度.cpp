/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (31.72%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    56.4K
 * Total Submissions: 177.8K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

// @lc code=start
#include<string>
using std::string;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        bool reset = false;
        for(auto c : s){
            if(c == ' '){
                reset = true;
            }
            else if(reset){
                reset = false;
                res = 1;
            }
            else{
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

