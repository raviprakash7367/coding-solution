/*
    name=  Linked List Cycle II
    link- https://leetcode.com/problems/linked-list-cycle-ii/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- take use of slow and fast pointer and when the both are equal then take 
              entry pointer at head and move 1-1 step both entry and slow pointer the collision
              point must be the entrance of loop;
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
    ListNode *detectCycle(ListNode *head) {
        if(head== NULL) return NULL;
        ListNode *slow= head;
        ListNode *fast= head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            
            slow= slow->next;
            fast= fast->next->next;
            if(slow== fast)
            {
                break;
            }
        }
        if(fast->next == NULL || fast->next->next == NULL) return NULL;
        
        ListNode *entry= head;
        while(entry!= NULL && entry != slow)
        {
            if(entry== slow)break;
            entry= entry->next;
            slow= slow->next;
            
        }
        return slow;
        
    }
};