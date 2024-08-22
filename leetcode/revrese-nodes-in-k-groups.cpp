/*
    name= Reverse Nodes in k-Group
    link-  https://leetcode.com/problems/reverse-nodes-in-k-group/
    author- Parth garg 
    time complexity- o(n)
    space complexity- o(1)
    method 1- for every group of k nodes reverse the list and connect these groups simultaneously;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 ) return head;
        
        int length=1;
        ListNode *temp= head;
        while(temp->next!= NULL)
        {
            temp= temp->next;
            length++;
        }
        
        ListNode* start= head;
        ListNode* linkPrev= start;
        int countGrpNum=0;
        while((length/k)>0)
        {
             
            int a= k-1;
            ListNode* prev= start;
            ListNode* curr= start->next;
            ListNode* nxt;
            if(start->next== NULL)return head;
            while(a--)
            {
                
                nxt= curr->next;
                curr->next= prev;
                prev= curr;
                curr= nxt;
            }
              
            if(countGrpNum==0)
            {
                head= prev;
            }
            else
            {
                linkPrev->next= prev;
                linkPrev= start;  
            }
            
            start= nxt;
            countGrpNum++;
            length-= k;
        }
        linkPrev->next= start;
        
        return head;
        
    }
};