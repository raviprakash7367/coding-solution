/*
    name=  Largest Palindromic Number
    link-  https://leetcode.com/problems/largest-palindromic-number/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n) // for storing resulting string
    method 1- hashing;
*/



class Solution {
public:
    string largestPalindromic(string nums){
        int hash[10]={0};
        for(int i=0;i<nums.length();i++)
        {
            hash[nums[i]-'0']++;
        }
        string front="";
        char mid='a';
        for(int i=9;i>0;i--)
        {
            int j= hash[i]/2;
            while(j--)
            {
                front+= ('0'+i);
            }
            if(hash[i]%2==1 && mid== 'a')
                mid= '0'+i; 
        }
        if(front.length()!=0)
        {    
            int j= hash[0]/2;
            while(j--)
            {
                front+='0';
            }
            if(hash[0]%2==1 && mid== 'a')
                mid= '0';
        }
        
        int len= front.length();
        if(mid!= 'a')
            front+= mid;
        
        for(int i=len-1;i>=0;i--)
        {
            front+= front[i];
        }
        return (front.length()==0)? "0" : front;
        
    }
};