/*
    name= word break
    link- https://practice.geeksforgeeks.org/problems/word-break1352/1
    author- Parth garg
    time complexity- o(n*s*12)
    space complexity- o(s)- stack
    method 1- recursion;
*/

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        if(A.length()==0) return 1;
        string s="";
        for(int i=0;i<A.length();i++){
            s+= A[i];
            if((find(B.begin(),B.end(),s)!= B.end()) && wordBreak(A.substr(i+1),B)){
                return 1;
            }
        }
        return 0;
    }
};