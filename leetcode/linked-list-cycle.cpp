
/*
    name= https://leetcode.com/problems/linked-list-cycle/
    link-  linked-list-cycle
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- take use of slow and fast pointer;
*/


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
    bool hasCycle(ListNode *head) {
        ListNode* slow= head;
        ListNode* fast= head;
        if(head== NULL )
        {
            return false;
        }
        while(fast->next != NULL && fast->next->next != NULL)
        {

            slow= slow->next;
            fast= fast->next->next;
            
            if(slow== fast)
            {
                return true;
            }
        }
        return false;
    }
};