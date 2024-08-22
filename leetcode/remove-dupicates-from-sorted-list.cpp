/*  
    name - remove duplicates form sorted list
    link- https://leetcode.com/problems/remove-duplicates-from-sorted-list/
    author- Parth garg
    time complexity- o(n)
    method 1- traverse the list and if next node value is same as previous then skip that node;
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev= head;
        if(head == NULL) return NULL;
        ListNode* temp= prev->next;
        while(temp != NULL)
        { 
            if(temp->val != prev->val)
            {
                prev->next = temp;
                prev= prev->next;
            }
            temp= temp->next;
        }
        prev->next= NULL;
        return head;
    }
};