/*
    name- excel sheet column title
    link- https://leetcode.com/problems/excel-sheet-column-title/
    author- Parth garg
    time complexity- O(log 26base n)
    method 1
*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        columnNumber--;
        while( columnNumber>=0 )
        {
            char c= 'A'+columnNumber%26;
            result= c+result;
            columnNumber/=26;
            columnNumber--;
        }
        return result;
    }
};