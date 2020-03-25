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

    }
};
// @lc code=end

// 标记做法
// 使用一个数组，标记着数组1内所有的数对应着的数组2的最小数值
// vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//     vector<vector<int>> res;
//     if(nums1.size() == 0 || nums2.size() == 0 || k == 0)
//     {
//         return res;
//     }
//     vector<int> vecNums2Index(nums1.size(),0);
//     int max = nums1[nums1.size()-1] + nums2[nums2.size()-1];
//     int mini = 0;
//     int miniIndex = 0;
//     while(res.size() < k && res.size() < nums1.size()*nums2.size())
//     {
//         mini = max;
//         for(int i=0; i<nums1.size(); i++)
//         {
//             if(vecNums2Index[i] < nums2.size() && nums1[i] + nums2[vecNums2Index[i]] <= mini)
//             {
//                 mini = nums1[i] + nums2[vecNums2Index[i]];
//                 miniIndex = i;
//             }
//         }
//         res.push_back({nums1[miniIndex], nums2[vecNums2Index[miniIndex]++]});
//     }
//     return res;
// }


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
