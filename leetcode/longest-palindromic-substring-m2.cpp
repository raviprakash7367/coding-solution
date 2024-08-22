/*
    name= longest palindromic substring
    link- https://leetcode.com/problems/longest-palindromic-substring/description/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- (o(1) + o(k)) for storing resulting substring
    method 2 - suppose length of substr is odd - take every element as center and use 2 pointers for finding max len 
               similarly do same thing for even case and take the maximum of both  
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        int st,end;
        int n= s.length();
        int max_len= -1;

        //for odd length
        for(int i=0;i<n;i++){
            int l= i,r=i;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            int len= r-l-1;
            if(len>max_len){
                max_len= len;
                st= l+1;
                end= r-1;
            }
        }
        //for even length
        for(int i=0;i<n-1;i++){
            int l= i,r=i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            int len= r-l-1;
            if(len>max_len){
                max_len= len;
                st= l+1;
                end= r-1;
            }
        }
        return s.substr(st,max_len);

    }
};