#
# @lc app=leetcode.cn id=974 lang=python3
#
# [974] 和可被 K 整除的子数组
#

# @lc code=start
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        s = 0
        res = 0
        M = []
        #
        for a in nums:
            s += a
            M.append(s % k)
        
        for k, v in Counter(M).items():
            if k == 0: res += v 
            res += v * (v-1) // 2
        return res
# @lc code=end

