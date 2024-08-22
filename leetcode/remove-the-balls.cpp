/*
    name= Remove the balls
    link- https://practice.geeksforgeeks.org/problems/546ea68f97be7283a04ddcc8057e09b46a686471/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- use stack;
*/

class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        stack<pair<int,int>>st;
        
        int i =1;
        st.push({color[0], radius[0]});
        while(i<n){
            pair<int,int>p= {color[i],radius[i]};
            if(!st.empty() && st.top() == p){
                st.pop();
                
            }
            else{
                st.push(p);
            }
            i++;
        }
        
        return st.size();
        
    }
};