/*
    ques name- length-of-last-word
    link- https://leetcode.com/problems/length-of-last-word/
    author- parth garg
    time complexity = o(n)
    method 1- start iterating from back if last elements are spaces then go to that nearest index which has any character other than space
    and then start counting until we don't find the next space
*/


class Solution {
public:
    int lengthOfLastWord(string s) {
        int i= s.length()-1;
        int count= 0;
        while(i>=0 && s[i]==' ')i--;
        while(i>=0 && s[i]!=' ')
        {
            count++;
            i--;
        }
        return count;
    }
};