
/*
    name= Delete Node in a Linked List
    link- https://leetcode.com/problems/delete-node-in-a-linked-list/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- use swaping ;
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
    void deleteNode(ListNode* node) {
        while(node->next->next != nullptr)
        {
            swap(node->val, node->next->val);
            node= node->next;
        }
        swap(node->val, node->next->val);
        node->next= NULL;
        
    }
};