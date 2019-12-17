/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (63.27%)
 * Likes:    357
 * Dislikes: 0
 * Total Accepted:    57.3K
 * Total Submissions: 90.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
 * 
 */

// @lc code=start
/*
思路：
    需要进行实际的结点变化，而在变化的过程中，需要参与的结点数，最低应该是3个，为了方便，直接使用到了4个结点
    1->2->3->4->5
    第一次变化将2->1->3->4->5   
    第二次则是2->1->4->3->5
*/
#if 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#endif
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode * res = head;
        int count = 0;
        ListNode * lastHead = head;
        ListNode * lastLastHead = head;
        ListNode * lastlastlastHead = nullptr;
        while(head != nullptr){
            if(lastlastlastHead != nullptr)
                lastlastlastHead = lastLastHead;
            lastLastHead = lastHead;
            lastHead = head;
            head = head->next;
            count++;
            if(count % 2 == 0){
                lastHead->next = lastLastHead;
                lastLastHead->next = head;
                if(lastlastlastHead != nullptr){
                    lastlastlastHead->next = lastHead;
                }
                else{
                    res = lastHead;
                    lastlastlastHead = lastHead;
                }
                lastHead = lastLastHead;
            }
        }
        return res;
    }
};
// @lc code=end

