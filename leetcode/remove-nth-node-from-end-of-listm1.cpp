
/*
    name= remove nth node from end of list
    link- https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
    author- Parth garg
    time complexity- o(n)
    method 1;
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp= head;
        if(temp== NULL || temp->next==NULL)
            return NULL;
        
        int count=0;
        while(temp!= NULL)
        {
            count++;
            temp= temp->next;
        }
        if(count==n) 
        {
            head= head->next;
            return head;
        }
        
        ListNode* p=head;
        count= count-n-1;
        while(count--)
        {
            p= p->next;
        }
        
        p->next= p->next->next;
        return head;
        
    }
};