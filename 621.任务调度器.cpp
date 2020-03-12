/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        for (int i = 0; i < tasks.size(); i++) {
            count[tasks[i]-'A']++;
        }//统计词频
        sort(count.begin(), count.end());//词频排序，升序排序，count[25]是频率最高的
        int maxCount = 0;
        //统计有多少个频率最高的字母
        for (int i = 25; i >= 0; i--) {
            if(count[i] != count[25]){
                break;
            }
            maxCount++;
        }
        int res =(count[25] - 1) * (n + 1) + maxCount;
        //公式算出的值可能会比数组的长度小，取两者中最大的那个
        return res > tasks.size() ? res : tasks.size();
    }
};
// @lc code=end

