/*
    name= keyboard row
    link- https://leetcode.com/problems/keyboard-row/
    author- Parth garg
    time complexity- o(n*m) , n= words.size, m= length of string
    method 1;
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>result;
        unordered_set<char>s1 = {'Q','W','E','R','T','Y','U','I','O','P','q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char>s2 = { 'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L'};
		unordered_set<char>s3 = { 'z','Z','x','X','c','C','v','V','b','B','n','N','m','M'};
        
        
        for(auto str: words)
        {
            bool flag1=true,flag2=true,flag3=true;
            for(auto ch : str)
            {
                if(flag1)
                {
                    if(s1.find(ch)== s1.end()) flag1= false;
                }
                if(flag2)
                {
                    if(s2.find(ch)== s2.end()) flag2= false;
                }
                if(flag3)
                {
                    if(s3.find(ch)== s3.end()) flag3= false;
                }   
            }
            if(flag1 || flag2 || flag3)
                result.push_back(str);
        }
        return result;
    }
};