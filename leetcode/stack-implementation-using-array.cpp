/*
    name= stack implementation using array
    link- https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209
    author- Parth garg
    time complexity- o(1) - every function
    space complexity- o(n) for n size stack
    method 1;
*/


#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    int *arr;
    int size;
    int topIndex;
    Stack(int capacity) {
        arr= new int[capacity];
        size= capacity;
        topIndex= -1;
    }

    void push(int num) {
        if(topIndex== size)return;
        else
        {
            topIndex++;
            arr[topIndex]= num;
        }
    }

    int pop() {
        if(topIndex== -1)return -1;
        else{
            topIndex--;
            return arr[topIndex+1];
        }
    }
    
    int top() {
        if(topIndex== -1) return -1;
        else return arr[topIndex];
    }
    
    int isEmpty() {
        if(topIndex== -1) return 1;
        else return 0;
    }
    
    int isFull() {
        if(topIndex== size-1) return 1;
        else return 0;
    }
    
};