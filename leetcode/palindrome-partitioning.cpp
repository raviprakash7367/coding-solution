/*
    name= palindrome partitioning
    link-  https://leetcode.com/problems/palindrome-partitioning/description/
    author- Parth garg
    time complexity- 
    space complexity-
    method 1;
*/


class Solution {
public:
    vector<vector<string>>result;

    bool checkPalindrome(string &s, int start, int end)
    {
        while(start<end)
        {
            if(s[start]!= s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void partitions(string &s, int i,vector<string>&temp)
    {
        if(i== s.length())
        {
            result.push_back(temp);
            return;
        }

        for(int k= i; k< s.length();k++)
        {
            if(checkPalindrome(s,i,k))
            {
                temp.push_back(s.substr(i,k-i+1));
                partitions(s,k+1,temp);
                temp.pop_back();
            }

        }

    }

    vector<vector<string>> partition(string s) {
        vector<string>temp;
        partitions(s,0,temp);
        return result;
    }
};