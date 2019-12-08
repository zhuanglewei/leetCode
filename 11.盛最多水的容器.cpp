/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
/*
This
*/
/*
暴力破解：
    求最大值问题，只需要求出所有值，也就知道最大值了
    所有俩俩之间的值，n个数值，复杂度为1+2+...+n-1=n*(n-1)/2=(n^2-n)/2，也就是O(n^2)的复杂度
动态规划优化：
    在暴力破解思路下，哪一些情况，是可以不需要计算的
    在前面的值，比后面的大，也就是距离更远，且值更大，这种情况，则不需要对后面的值进行判断，只需要拿当前的板乘以距离， 比较即可

*/
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        // 暴力破解法
        // for(int i=1; i<height.size(); i++)
        // {
        //     for(int j=0; j<i; j++)
        //     {
        //         int mid = (i-j) * ( (height[i] > height[j] ) ? height[j] : height[i]);
        //         if(mid > result)
        //             result = mid;
        //     }
        // }

        //仅判断对增大的值
		// vector<int> numSite{0};
		// int startSite = 0;
		// for (int i = 1; i < height.size(); i++)
		// {
		// 	for (int item = startSite; item < numSite.size(); item++)
		// 	{
		// 		int mid = (i - numSite[item]) * ((height[i] > height[numSite[item]]) ? height[numSite[item]] : height[i]);
		// 		if (mid > result)
		// 		{
		// 			result = mid;
		// 			if (item > startSite)
		// 			{
		// 				startSite = item;
		// 			}
		// 			for (int j = 0; j < startSite; j++)
		// 			{
		// 				mid = (i - numSite[j]) * ((height[i] > height[numSite[j]]) ? height[numSite[j]] : height[i]);
		// 				if (mid > result)
		// 					result = mid;
		// 			}
		// 		}
		// 	}
		// 	if (height[i] > height[numSite[numSite.size() - 1]])
		// 		numSite.push_back(i);
		// }

        //宽高判断，俩边同时，那边矮，哪边移动
        int leftIndex = 0;
        int rightIndex = height.size()-1;
        int width = 0;
        int hight = 0;
        int mid = 0;
        while(leftIndex < rightIndex)
        {
            width = rightIndex-leftIndex;
            if(height[leftIndex]>height[rightIndex])
            {
                hight = height[rightIndex];
                rightIndex--;
            }
            else{
                hight = height[leftIndex];
                leftIndex++;
            }
            mid = width * hight;
            if(mid > result)
                result = mid;
        }
        return result;
    }
};

