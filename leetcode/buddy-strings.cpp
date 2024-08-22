/*
    name= Buddy string
    link- https://leetcode.com/problems/buddy-strings/
    author- Parth garg
    time complexity- o(n)
    method 1;
*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()<2) return false;
        if(s.length()==2) 
        {
            swap(s[0],s[1]);
            if(s== goal ) return true;
            else return false;
        }
        else
        {
            int hash[26]={0};
            vector<int>v;
            for(int i=0;i<s.length();i++)
            {
                hash[s[i]-'a']++;
                if(s[i] != goal[i])
                {
                    v.push_back(i);
                }
            }
            if(v.size()==2)
            {
                swap(s[v[0]],s[v[1]]);
                if(s== goal) return true;
                else return false;
            }
            else if(v.size()==0)
            {
                for(int i=0;i<26;i++)
                    if(hash[i]>=2) return true;
                
                return false;
            }
            else return false;
        }
    }
};