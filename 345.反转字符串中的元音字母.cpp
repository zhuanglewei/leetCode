/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (48.37%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    20.2K
 * Total Submissions: 41.8K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */

// @lc code=start
/*
初次做法
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;
        char mid;
        while(left < right){
            while(!vowel(s[left])){
                left++;
                if(left >= right)
                    return s;
            }
            while(!vowel(s[right])){
                right--;
                if(left >= right)
                    return s;
            }
            mid = s[left];
            s[left] = s[right];
            s[right] = mid;
            left++;
            right--;
        }
        return s;
    }
    bool vowel(char a){
        if(a=='a' || a=='o' || a=='e' || a=='i' || a=='u' || 
           a=='A' || a=='O' || a=='E' || a=='I' || a=='U'){
            return true;
        }
        return false;
    }

*/

#include<string>
#include<algorithm>
#include<unordered_map>
using std::unordered_map;
using std::string;
class Solution {
public:
    string reverseVowels(string s) 
    {
        int i=0,j=s.size()-1;
        string tool="aoeiuAOEIU";
        while(i<j)
        {
            while(tool.find(s[i])==-1&&i<j)
                ++i;
            while(tool.find(s[j])==-1&&i<j)
                --j;
            if(i<j)
                swap(s[i++],s[j--]);
        }
        return s;
    }
};
// @lc code=end

