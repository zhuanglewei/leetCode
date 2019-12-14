/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (72.48%)
 * Likes:    647
 * Dislikes: 0
 * Total Accepted:    59K
 * Total Submissions: 81.3K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;

/*
    括号必须成对存在,必须先存在'(‘后才能有')'
    所以每次添加的时候，必须先检查字符串的状态
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res{""};
        int midState = 0;
        for(int i=0; i<n*2-1; i++){
            vector<string> temp;
            for(string str: res){
                midState = check(str,n);
                switch (midState)
                {
                case 0:
                    str+='(';
                    temp.push_back(str);
                    str[i]=')';
                    temp.push_back(str);
                    break;
                case 1:
                    str+=string(n*2-str.size(), ')');
                    temp.push_back(str);
                    break;
                case 2:
                    str+='(';
                    temp.push_back(str);
                    break;
                case 3:
                    str += "()";
                    temp.push_back(str);
                    break;
                default:
                    temp.push_back(str);
                    break;
                }
            }
            res = temp;
        }
        return res;
    }
    int check(string str, int n){
        if(str.size() == n*2)
            return -1;
        int left=0;
        int right=0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '(')
                left++;
            else 
                right++;
        }
        if(left > right){
            if(left < n)
                return 0;   //可以添加（或）
            else
                return 1;   //仅可以添加)          
        }
        else 
        {
            if (str.size() + 2 == n * 2)
			    return 3;
            else 
                return 2;       //仅可以添加（
        }   
    }
};
// @lc code=end

