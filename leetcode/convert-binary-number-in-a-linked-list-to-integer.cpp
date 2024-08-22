
/*  
    name - convert-binary-number-in-a-linked-list-to-integer
    link- https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
    author- Parth garg
    time complexity- o(n)
    method 1-  do result= (result+ temp->val)*2 
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
    int getDecimalValue(ListNode* head) {
        int result =0;
        ListNode* temp= head;
        while(temp->next != NULL)
        {
            result = (result+temp->val)*2;
            temp= temp->next;
        }
        if(temp->val== 1) return result= result+1;
        else return result;
        
    }
};