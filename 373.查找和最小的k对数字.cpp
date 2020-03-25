/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

// @lc code=start
#include <vector>
#include <map>
using std::vector;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        std::map<int, vector<vector<int>>> map;
        if(nums1.size() == 0 || nums2.size() == 0 || k == 0)
        {
            return res;
        }
        int Index1 = 0, Index2 = 0;
        for(auto i : nums1)
        {
            for(auto j : nums2)
            {
                map[i+j].push_back({i,j});
            }
        }
        auto it = map.begin();
        while (k > 0 && it!= map.end())
        {
            for(auto vec : it->second)
            {
                res.push_back(vec);
                if(--k<=0)
                    break;
            }
            it++;
        }
        return res;
    }
};
// @lc code=end

// 容器做法，能够算出答案，但性能不好
//
// vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//     vector<vector<int>> res;
//     std::map<int, vector<vector<int>>> map;
//     if(nums1.size() == 0 || nums2.size() == 0 || k == 0)
//     {
//         return res;
//     }
//     int Index1 = 0, Index2 = 0;
//     for(auto i : nums1)
//     {
//         for(auto j : nums2)
//         {
//             map[i+j].push_back({i,j});
//         }
//     }
//     auto it = map.begin();
//     while (k > 0 && it!= map.end())
//     {
//         for(auto vec : it->second)
//         {
//             res.push_back(vec);
//             if(--k<=0)
//                 break;
//         }
//         it++;
//     }
//     return res;
// }
