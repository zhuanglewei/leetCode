/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 解题思路：
// 双指针法：一个指针指向结果，一个指针指向末尾，但后一个指针移动两位时，前一个指针移动一位
// 注意的点：链表个数为1时  链表个数为偶数时

// Problem solving ideas:
// Double pointer method: one pointer points to the result, one pointer points to the end, 
//                        but when the next pointer moves two places, 
//                        the previous pointer moves one place
// Note: when the number of linked lists is even

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * res = head;
        ListNode * right = head->next;
        int count = 1;
        while(right != nullptr)
        {
            right = right->next;
            if(count++ % 2 == 1)
            {
                res = res->next;
            }
        }
        return res;
    }
};
// @lc code=end

