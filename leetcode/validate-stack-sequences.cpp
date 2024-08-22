/*
    name= validate stack sequences
    link- https://leetcode.com/problems/validate-stack-sequences/description/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- stack;
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int n= pushed.size();
        // vector<int>hash(1001,0);
        int j= 0;
        int i=0;
        while(j<n){
            if(!st.empty() && st.top()== popped[j]){
                st.pop();
                j++;
            }
            else{
                if(i== n  && !st.empty() && st.top()!= popped[j])return false;
                st.push(pushed[i]);
                i++;
                // hash[pushed[i]]= 1;
            }
        }
        return true;
    }
};