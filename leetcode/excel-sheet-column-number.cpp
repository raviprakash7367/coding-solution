/*
    name- excel sheet column number
    link- https://leetcode.com/problems/excel-sheet-column-number/
    author- parth garg
    time complexity- o(n)
    method 1
*/


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int value=0;
        reverse(columnTitle.begin(),columnTitle.end());
        for(int i= 0;i<columnTitle.length();i++)
        {
            value+= pow(26,i)*(columnTitle[i]-'A'+1);
        }
        return value;
    }
};