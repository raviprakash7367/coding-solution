/*
    name= intersection-of-two-linked-lists
    link- https://leetcode.com/problems/intersection-of-two-linked-lists/
    author- Parth garg
    time complexity- o(m+n)
    space complexity- o(1)
    method 1- find the difference of length of both list and then run the larger list differnce 
              steps forward then run both list simultaneously and check for same node;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=1,len2=1;
        int diff;
        ListNode *run1= headA;
        ListNode *run2= headB;
        while(run1->next != NULL)
        {
            run1= run1->next;
            len1++;
        }
        while(run2->next != NULL)
        {
            run2= run2->next;
            len2++;
        }
        diff= abs(len1-len2);
        run1= headA;
        run2= headB;
        if(len1>len2)
        { 
            while(diff--)
            {
                run1= run1->next;
            }
        }
        else 
        {
            while(diff--)
            {
                run2= run2->next;
            }
        }
        while(run1!= run2)
        {
            run1= run1->next;
            run2= run2->next;
        }
        return run1;
    }
};