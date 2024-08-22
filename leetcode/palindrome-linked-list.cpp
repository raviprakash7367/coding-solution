/*
    name= Palindrome Linked List
    link- https://leetcode.com/problems/palindrome-linked-list/
    author- Parth garg 
    time complexity- o(n)
    space complexity- o(1)
    method 1- reverse the second half of list and then check for both halves;
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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        if(!head->next->next)
        {
            if(head->val != head->next->val) return false;
            else return true;
        }
        if(!head->next->next->next)
        {
            if(head->val != head->next->next->val) return false;
            else return true;
        }
        
        // if size of list greater than 3 
        
        ListNode *slow= head;
        ListNode *fast= head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow= slow->next;
            fast= fast->next->next;
        }
        
        
        //slow = if(even length) last element of first half
        //       if(odd length) middle element of list
        
        ListNode *secHalf= slow->next;
        
        ListNode *prev= secHalf;
        ListNode *curr= secHalf->next;
        ListNode *nxt;
        secHalf->next= NULL;
        slow->next= NULL;
        
        while(curr!= NULL)
        {
            nxt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nxt;
        }
        
        secHalf= prev;
        
        // revresing done now check for both the halves
        ListNode *firstHalf= head;
        
  
        while(secHalf != NULL && firstHalf != NULL)
        {
            if(firstHalf->val != secHalf->val) return false;
            
            firstHalf= firstHalf->next;
            secHalf= secHalf->next;
        }
        return true;
        
    }
};