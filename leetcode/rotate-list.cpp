/*
    name= rotate list
    link- https://leetcode.com/problems/rotate-list/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head ==  NULL || head->next == NULL) return head;
        
        int length=0;
        ListNode *temp= head;
        ListNode *end;
        while(temp != NULL)
        {
            length++;
            end= temp;
            temp= temp->next;
        }
        
        k= length- (k%length) -1 ;
        
        ListNode *start= head;
        while(k--)
        {
            start= start->next;
        }
        
        end->next= head;
        head= start->next;
        start->next= NULL;
        return head;
    
    }
};