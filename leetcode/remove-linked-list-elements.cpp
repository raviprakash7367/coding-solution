

/*  
    name - remove linked list elemets
    link- https://leetcode.com/problems/remove-linked-list-elements/
    author- Parth garg
    time complexity- o(n)
    method 1
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head== NULL) return head;
        
        ListNode* temp= head;
        
        //delete from head
        
        if(head->val == val)
        {
            ListNode* prev= head;
            while(temp!=NULL)
            {
                if(temp->val != val)
                {
                   break; 
                }
                prev= temp;
                temp= temp->next;
            }
            head = prev->next;
        }
        // head->next= temp at this point
        // at this point temp is either NULL or contains a value that is different from val 
        
        if(temp==NULL) return head;
        ListNode* prev= temp;
        temp= temp->next;
        
        while(temp!=NULL)
        {
            if(temp->val== val)
            {
                prev->next= temp->next;
            }
            else
            {
                prev= temp;
            }
            
            temp= temp->next;
        }
        return head;
        
        
    }
};







