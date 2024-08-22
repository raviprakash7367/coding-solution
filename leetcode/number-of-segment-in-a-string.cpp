
/*
    name= number of segments in a string
    link- https://leetcode.com/problems/number-of-segments-in-a-string/
    author- Parth garg
    time complexity- o(n)
    method 1= go to every element and break the loop if we get ' ' ;
*/

class Solution {
public:
    int countSegments(string s) {
        int i=0,j=0;
        int count=0;
        while(s[i]==' ')
        {
            i++;j++;
        }
        while(i<s.length() && j< s.length())
        {
            if(s[i]!=' ') count++;
            
            while(j<s.length())
            {
                if(s[j]==' ') break;
                j++;
            }
            j++;
            i=j;
        }
        
        return count;
    }
};