/*
    name= palindrome with minimum sum
    link- https://practice.geeksforgeeks.org/problems/32dc957908c2eb8beeeaeedf81f37df20d37c308/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/
class Solution {
  public:
    int minimumSum(string s) {
        int l= 0,r= s.length()-1;
        int n= s.length();
        while(l<r){
            if(s[l] != s[r]){
                if(s[l] == '?' && s[r]=='?'){
                    continue;
                }
                else if(s[l] == '?'){
                    s[l] = s[r];
                }
                else if(s[r] == '?'){
                    s[r]= s[l];
                }
                else{
                    return -1;
                }
            } 
            l++;r--;
        }
        
        char prev = s[0];
        int count =0;
        for(int i=0;i<n;i++){
            if(s[i] == '?')continue;
            else{
                if(prev == '?') {
                    prev = s[i];
                }
                else{
                    count+= (abs(s[i]- prev));
                    prev = s[i];
                }
            }
        }
        return count;
        
        
    }
};