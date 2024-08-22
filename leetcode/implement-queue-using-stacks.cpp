/*
    name= implement queue using stacks (two stack)
    link- https://leetcode.com/problems/implement-queue-using-stacks/description/
    author- Parth garg
    time complexity- insertion o(n) else o(1)
    space complexity- o(n)
    method 1;
*/

class MyQueue {
public:
    stack<int>s1;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int>s2;
        while(s1.size()!=0)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()!=0)
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(s1.size()!=0)
        {
            int data= s1.top();
            s1.pop();
            return data;
        }
        else return -1;
    }
    
    int peek() {
        if(s1.size()!=0) return s1.top();
        else return -1;
    }
    
    bool empty() {
        return s1.size()>0? false: true ;
    }
};
