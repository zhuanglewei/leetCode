/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    static bool cmp (vector<int> & a,vector<int> & b) {
	    {
            if(a[0] > b[0])         // 按数组第一列从大到小排序
                return true;
            if(a[0] == b[0] && a[1] <b[1]) // 按数组第二列从小到大排序
                return true;
            return false;
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> results;
        // 排序完成后，按照区间第二列元素给出的位置插入人。
        for(int i = 0; i < people.size(); i++) {
            results.insert(results.begin()+people[i][1],people[i]);
        }
        return results;
    }
};
// @lc code=end

