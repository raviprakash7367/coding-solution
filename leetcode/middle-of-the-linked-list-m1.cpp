
/*
    name= Middle of the linked list
    link- https://leetcode.com/problems/reverse-linked-list/
    author- Parth garg
    time complexity- O(n)
    method 1- first find the total no. of nodes and then iterate 
            for half of the count until we reach the middle node;
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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        int count=0;
        ListNode* temp= head;
        while(temp != NULL)
        {
            temp= temp->next;
            count++;
        }
        count/=2;
        ListNode* result= head;
        while(count--)
        {
            result= result->next;
        }
        return result;
    }
};