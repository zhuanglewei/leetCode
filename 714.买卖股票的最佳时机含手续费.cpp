/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0;
        int buyPrice = prices[0];
        int sellPrice = buyPrice;
        for(auto i : prices)
        {
            if(i >= sellPrice)
            {
                sellPrice = i;
            }
            else 
            {
                if(sellPrice - i <= fee && i >= buyPrice)
                {
                    continue;
                }
                else{
                    int mid = sellPrice - buyPrice - fee;
                    if(mid > 0)
                    {
                        res += mid;
                        buyPrice = i;
                        sellPrice = i;
                    }
                    else if(i < buyPrice){
                        buyPrice = i;
                        sellPrice = i;
                    }
                }
            }
        }
        int mid = sellPrice - buyPrice - fee;
        return mid > 0 ? res+mid : res;
    }
};
// @lc code=end

