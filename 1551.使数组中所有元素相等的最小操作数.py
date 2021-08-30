#
# @lc app=leetcode.cn id=1551 lang=python3
#
# [1551] 使数组中所有元素相等的最小操作数
#
# https://leetcode-cn.com/problems/minimum-operations-to-make-array-equal/description/
#
# algorithms
# Medium (81.73%)
# Likes:    24
# Dislikes: 0
# Total Accepted:    10.9K
# Total Submissions: 13.3K
# Testcase Example:  '3'
#
# 存在一个长度为 n 的数组 arr ，其中 arr[i] = (2 * i) + 1 （ 0 <= i < n ）。
# 
# 一次操作中，你可以选出两个下标，记作 x 和 y （ 0 <= x, y < n ）并使 arr[x] 减去 1 、arr[y] 加上 1 （即
# arr[x] -=1 且 arr[y] += 1 ）。最终的目标是使数组中的所有元素都 相等 。题目测试用例将会 保证
# ：在执行若干步操作后，数组中的所有元素最终可以全部相等。
# 
# 给你一个整数 n，即数组的长度。请你返回使数组 arr 中所有元素相等所需的 最小操作数 。
# 
# 
# 
# 示例 1：
# 
# 输入：n = 3
# 输出：2
# 解释：arr = [1, 3, 5]
# 第一次操作选出 x = 2 和 y = 0，使数组变为 [2, 3, 4]
# 第二次操作继续选出 x = 2 和 y = 0，数组将会变成 [3, 3, 3]
# 
# 
# 示例 2：
# 
# 输入：n = 6
# 输出：9
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 10^4
# 
# 
#

# @lc code=start
class Solution:
    def minOperations(self, n: int) -> int:
        ans = 0
        for num in range(1, n // 2 + 1):
            ans += n - (num * 2 - 1)
        return ans

# @lc code=end

