

/*
    name= add strings
    link- https://leetcode.com/problems/add-strings/
    author- Parth garg
    time complexity- o(n)
    method 1;
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int l1= num1.length();
        int l2= num2.length();
        int maxLen= max(l1,l2);
        int carry= 0;
        int i=l1-1;
        int j= l2-1;
        while(maxLen--)
        {
            int a= (i>=0)?(num1[i]-'0'): 0;
            int b= (j>=0)?(num2[j]-'0'): 0;
            int sum= a+b+ carry;
            carry=0;
            if(sum>=10) 
                carry= sum/10, sum=sum%10;
            
            char c= '0'+sum;
            result= c+ result;
            i--;j--;
        }
        if(carry !=0)
        {
            char c= ('0'+carry);
            result= c + result;
        }
        return result;
    }
};