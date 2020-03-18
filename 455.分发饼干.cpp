/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res=0;
        for(auto i : s)
        {
            if(i >= g[res])
            {
                res++;
            }
            if(res == g.size())
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

