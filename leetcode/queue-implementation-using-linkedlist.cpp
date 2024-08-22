/*
    name= queue implementation using linked list
    link- https://www.codingninjas.com/codestudio/problems/2099908?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
    author- Parth garg
    time complexity-  o(1) all operations
    space complexity- o(n) n= number of nodes
    method 1;
*/


#include <bits/stdc++.h> 
class Queue {
public:
    
    class node{
        public: 
        int data;
        node* next;
        node(int data)
        {
            this->data= data;
            this->next= NULL;
        }
    };
    
    node *head, *tail;
    int size;
    
    Queue() {
        size=0;
        head= NULL;
        tail= NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(size==0) return true;
        else return false;
    }

    void enqueue(int data) {
        node *newnode= new node(data);
        if(size==0)
        { 
            head= newnode;
            tail= newnode;
        }
        else
        {
            tail->next= newnode;
            tail = tail->next;
        }
        size++;
    }

    int dequeue() {
        if(size==0) 
        {
            return -1;
        }
        else
        {
            int val= head->data;
            node *n= head;
            head= head->next;
            n->next= NULL;
            free(n);
            size--;
            return val;
        }
    }

    int front() {
        if(head!= NULL) return head->data;
        else return -1;
    }
};