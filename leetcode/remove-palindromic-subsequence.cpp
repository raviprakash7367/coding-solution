
/*
    name= remove palindromic subsequence
    link- https://leetcode.com/problems/remove-palindromic-subsequences/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- ans can be only 1 or 2  if string is not palindrome then in 1st step delete all a's and then delete all b's; 
*/


class Solution {
public:
    

    int removePalindromeSub(string a) {
        
        for(int i=0;i<a.length()/2;i++)
        {
            if(a[i]!= a[a.length()-1-i]) return 2;
        }
        return 1;
        
    }
};