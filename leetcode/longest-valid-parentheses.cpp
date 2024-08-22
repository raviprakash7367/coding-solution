/*
    name= longest valid parentheses
    link- https://leetcode.com/problems/longest-valid-parentheses/description/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1 - replace all valid substrings with star and find maximum length substring; 
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int max_len=0,len=0;
        int n= s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(!st.empty() && s[i]==')'){
                int idx= st.top();
                s[idx]= '*';
                s[i]= '*';
                st.pop();
            }
        }
        // cout<<s<<endl;
        for(int i=0;i<n;i++){
            if(s[i]!= '*'){
                max_len= max(max_len, len);
                len=0;
            }
            else{
                len++;
            }
        }
        max_len= max(max_len,len);
        return max_len;
        
    }
};