/*
    name= add two numbers
    link- https://leetcode.com/problems/add-two-numbers/
    author- Parth garg
    time complexity- o(n)
    method 1-  ListNode* temp= new ListNode(value);  is used for making new node 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp= new ListNode(0);
        ListNode* result= temp;

        int carry= 0;
        
        while(l1 || l2)
        {   

            int sum;
            if(l1== NULL ) { sum= l2->val+ carry;l2= l2->next;}
            else if(l2== NULL) { sum= l1->val+ carry; l1= l1->next;}
            else  {sum= l1->val + l2->val+ carry;l2= l2->next; l1=l1->next;}

            carry=0;
            temp->next = new ListNode(sum%10);
            temp= temp->next;            
            carry= sum/10;
            
        }
        if(carry!= 0) 
        {
            temp->next = new ListNode(carry);            
            temp= temp->next;
            temp->next= NULL;
        }
        
        return result->next;
        
    }
};