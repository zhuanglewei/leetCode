/*
 * @lc app=leetcode.cn id=335 lang=cpp
 *
 * [335] 路径交叉
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if(x.size() < 4){
            return false;
        }
        if (x[3] >= x[1] && x[0] >= x[2]) {
            return true;
        }
        if (x.size() >= 5 && x[3] == x[1] && x[4] >= x[2] - x[0]) {
            return true;
        }
        for (int i = 5; i < x.size(); ++i) {
            if (x[i-2] >= x[i-4] && x[i-3] >= x[i-1] && x[i-1] >= x[i-3] - x[i-5] && x[i] >= x[i-2] - x[i-4]) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

