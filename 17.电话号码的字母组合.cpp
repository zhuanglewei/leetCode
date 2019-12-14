/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (51.60%)
 * Likes:    514
 * Dislikes: 0
 * Total Accepted:    62.8K
 * Total Submissions: 121.6K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> numStr{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result{""};
        if(digits.size()==0) return {};
        for(int i=0;i<digits.size();i++){
            vector<string> temp;
            string str = numStr[num(digits[i])];
            for(int j=0;j<str.size();j++){
                for(string s:result) 
                    temp.push_back(s+str[j]);
            }
            result = temp;
        }
        return result;
    }

    
    int num(char a){
        switch (a)
        {
        case '2':
            return 0;
        case '3':
            return 1;
        case '4':
            return 2;
        case '5':
            return 3;
        case '6':
            return 4;
        case '7':
            return 5;
        case '8':
            return 6;
        case '9':
            return 7;
        default:
            return 0;
        }
    }
};
// @lc code=end

