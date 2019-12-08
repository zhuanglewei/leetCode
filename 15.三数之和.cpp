/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            思路一： 暴力破解   -结局超时
                    参考俩数之和，利用散列表，一个数，查找相加为0的另一个元素，此次另一个元素改为两数之和
                    步骤一：获取俩数之和散列表 
                    步骤二：遍历查找    复杂度N
                边界条件：俩数之和可能相同，但元素不同
                         前面使用过的数字，后面再次使用
                         三元组必须不同，{-1，-1，1， 0}，只能有一组{-1， 0， 1}
        */
        // vector<vector<int>> result;
        // unordered_map<int,vector<vector<int>>> sumMap;
        // unordered_map<int, vector<int>> onlyMap;
        // int sum=0;
        // int big,smart,middle;
        // for(int i = 1; i< nums.size(); i++){
        //     for(int j=0; j<i; j++){
        //         sum = nums[i] + nums[j];
        //         vector<int> mid{i, j};
        //         unordered_map<int,vector<vector<int>>>::iterator it = sumMap.find(sum);
        //         if(it != sumMap.end()){ //同一个sum可能由不同的数值元素组成
        //             it->second.push_back(mid);
        //         }
        //         else{
        //             sumMap[sum] = vector<vector<int>>{mid};
        //         }
        //     }
        // }
        // for(int i=0; i<nums.size(); i++){
        //     int otherNum = 0 - nums[i];
        //     unordered_map<int,vector<vector<int>>>::iterator it = sumMap.find(otherNum);
        //     if(it != sumMap.end()){
        //         for(vector<int> item : it->second){
        //             smart = nums[item[0]] < nums[item[1]] ? nums[item[0]] : nums[item[1]];
        //             big = it->first - smart;
        //             //判断元素是否唯一，且答案是否唯一
        //             if(i != item[0] && i != item[1] && i<item[0] && i<item[1]){
        //                 if(nums[i] > big){
        //                     middle = big;
        //                     big = nums[i];
        //                 }
        //                 else if(nums[i] > smart){
        //                     middle = nums[i];
        //                 }
        //                 else{
        //                     middle = smart;
        //                     smart = nums[i];
        //                 }
        //                 vector<int> mid{smart, middle, big};
        //                 unordered_map<int,vector<int>>::iterator onlyMapIt = onlyMap.find(smart);
        //                 if(onlyMapIt != onlyMap.end()){
        //                     bool add = true;
        //                     for(int j : onlyMapIt->second){
        //                         if(j == middle){
        //                             add = false;
        //                             break;
        //                         }
        //                     }
        //                     if(add){
        //                         result.push_back(mid);
        //                         onlyMap[smart].push_back(middle);
        //                     }
        //                 }
        //                 else{
        //                     result.push_back(mid);
		// 					vector<int> vecOnly{ middle };
		// 					onlyMap[smart] = vecOnly;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return result;
        /*
            排序后，双指针取值判断
        */
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int> > res;
        for (int i = 0; i < N - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = N - 1;
            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];
                if (s > 0) {
                    --r;
                } else if (s < 0) {
                    ++l;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[++l]);
                    while (l < r && nums[r] == nums[--r]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

