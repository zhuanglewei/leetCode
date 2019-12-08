/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <string>
#include <vector>
using std::string;
using std::vector;
// @lc code=start
/*
    思路一：将字符串按照Z型变换，分为n个字符串，再把n个字符串相加，注意边界条件判断
            vector初始化，否则下标越界问题
*/
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vecString{numRows, ""};
        string result;
        bool addRow = true;
        int nowRow = 0;
        for(int i=0; i<s.size(); i++){
            vecString[nowRow] += s[i];
            if(addRow && nowRow < numRows - 1){
                nowRow++;
            }
            else if(!addRow && nowRow > 0){
                nowRow--;
            }
            if(nowRow == numRows-1){
                addRow = false;
            }
            else if(nowRow == 0){
                addRow = true;
            }
        }
        for(string item : vecString)
        {
            result += item;
        }
        return result;
    }
};
// @lc code=end

