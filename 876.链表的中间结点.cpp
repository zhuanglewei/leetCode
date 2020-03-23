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

