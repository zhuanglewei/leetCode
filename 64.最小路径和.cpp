/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        vector<vector<int>> dp(x, vector<int>(y));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < x; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int j = 1; j < y; j++){
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for(int i = 1; i < x; i++){
            for(int j = 1; j < y; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[x - 1][y - 1];
    }
};
// @lc code=end

