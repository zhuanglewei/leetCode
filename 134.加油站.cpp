/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0;
        vector<int> mid;
        int balance = 0;
        for(int i=0; i<gas.size(); i++)
        {
            balance += gas[i] - cost[i];
            if(balance < 0)
            {
                balance = 0;
                res = i+1;
            }
            mid.push_back(gas[i] - cost[i]);
        }
        if(res >= gas.size())
        {
            return -1;
        }
        for(int i=0; i<res; i++)
        {
            balance += mid[i];
        }
        return balance < 0 ? -1 : res;
    }
};
// @lc code=end

