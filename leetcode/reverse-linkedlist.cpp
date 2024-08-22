/*
    name= reverse linked list
    link- https://leetcode.com/problems/reverse-linked-list/
    author- Parth garg
    time complexity- O(n)
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
    ListNode* reverseList(ListNode* head) {
        if(head== NULL || head->next==NULL ) return head;
        
        ListNode* prev= head; 
        ListNode* temp= head->next;
        ListNode* next= temp->next;
        
        while(next != NULL)
        {
            temp->next= prev;
            prev= temp;
            temp= next;
            next= temp->next;
        }
        head->next= NULL;
        temp->next= prev;
        return temp;
    }
};