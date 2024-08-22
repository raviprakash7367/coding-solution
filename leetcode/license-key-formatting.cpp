
/*
    name= licence-key-formatting
    link- https://leetcode.com/problems/license-key-formatting/
    author- Parth garg
    time complexity- o(n)
    method 1;
*/
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result="";
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]== '-')
            {
                s.erase(i,1);
                i++;
            }
            s[i] = toupper(s[i]); 
        }
        int l= s.length();
        if(s.length()<=1) return s;
        result = s.substr(0,l%k);
        int temp= l/k;
        int i= l%k ;
        while(temp--)
        {
            result+= "-";
            result+= s.substr(i,k);
            i+=k;
        }
        if(result[result.length()-1]=='-') result.erase(result.length()-1, 1);
        if(result[0]=='-') result.erase(0,1);
        return result;
        
    }
};