/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int listCount1 = 0;
        int listCount2 = 0;
        ListNode * list1 = l1;
        ListNode * list2 = l2;
        while(list1 != nullptr)
        {
            listCount1++;
            list1 = list1->next;
        }
        while(list2 != nullptr)
        {
            listCount2++;
            list2 = list2->next;
        }

        ListNode * resNode = nullptr;
        ListNode * lastNode = nullptr;
        ListNode * reserveNode = nullptr;
        while(listCount1 > listCount2)
        {
            if(lastNode == nullptr)
            {
                resNode = new ListNode(l1->val);
                lastNode = resNode;
                reserveNode = lastNode;
            }
            else{
                lastNode->next = new ListNode(l1->val);
                lastNode = lastNode->next;
                if(lastNode->val != 9)
                    reserveNode = lastNode;
            }
            l1 = l1->next;
            listCount1--;
        }
        while(listCount1 < listCount2)
        {
            if(lastNode == nullptr)
            {
                resNode = new ListNode(l2->val);
                lastNode = resNode;
                reserveNode = lastNode;
            }
            else{
                lastNode->next = new ListNode(l2->val);
                lastNode = lastNode->next;
                if(lastNode->val != 9)
                    reserveNode = lastNode;
            }
            l2 = l2->next;
            listCount2--;
        }

        int mid = 0;
        while(l1 != nullptr)
        {
            mid = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            if(resNode == nullptr)
            {
                if(mid >= 10)
                {
                    resNode = new ListNode(1);
                    resNode->next = new ListNode(mid%10);
                    lastNode = resNode->next;
                    reserveNode = resNode->next;
                }
                else
                {
                    resNode = new ListNode(mid);
                    if(mid == 9 && l1 != nullptr && l1->val + l2->val >= 10)
                    {
                        ListNode * node = new ListNode(1);
                        node->next = resNode;
                        resNode->val = 0;
                        resNode->next = new ListNode((l1->val + l2->val)%10);
                        lastNode = resNode->next;
                        reserveNode = resNode->next;   
                        resNode = node;
                        l1 = l1->next;
                        l2 = l2->next;
                    }
                    else{
                        lastNode = resNode;
                        reserveNode = lastNode;
                    }
                }            
            }
            else{
                if(mid >= 10)
                {
                    lastNode->next = new ListNode(mid%10);
                    lastNode = lastNode->next;
                    if(reserveNode == resNode && reserveNode->val == 9)
                    {
                        ListNode * node = new ListNode(1);
                        node->next = resNode;
                        resNode = node;
                    }
                    while(reserveNode != lastNode)
                    {
                        reserveNode->val = (reserveNode->val+1)%10;
                        reserveNode = reserveNode->next;
                    }
                    reserveNode = lastNode;
                }
                else{
                    lastNode->next = new ListNode(mid);
                    lastNode = lastNode->next;
                    if(lastNode->val != 9)
                        reserveNode = lastNode;
                }
            }
        }
        return resNode;
    }
};
// @lc code=end

