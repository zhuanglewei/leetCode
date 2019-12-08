/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#if 0
#define NULL 0
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 #endif

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //链表的基础操作
        ListNode * pResult = NULL;
        ListNode * pNode = NULL;
        int nTen = 0;                               //相加大于10时，下一位需+1
        while(l1 !=NULL || l2 != NULL){
            int nVal;
            if (l1 != NULL && l2 != NULL)
            {
                nVal = l1->val + l2->val + nTen;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 != NULL)
            {
                nVal = l1->val + nTen;
                l1 = l1->next;
            }
            else
            {
                nVal = l2->val + nTen;
                l2 = l2->next;
            }
            if (nVal >= 10)
            {
                nTen = 1;
                nVal %= 10;
            }
            else
            {
                nTen = 0;
            }
            
            ListNode * pMidNode = new ListNode(nVal);
            if (pResult == NULL)
            {
                pNode = pMidNode;
                pResult = pNode;
            }
            else{
                pNode->next = pMidNode;
                pNode = pMidNode;
            }
        }
        if (nTen == 1)
        {
            ListNode * pMidNode = new ListNode(1);
            pNode->next = pMidNode;
        }
        return pResult;
    }
};


