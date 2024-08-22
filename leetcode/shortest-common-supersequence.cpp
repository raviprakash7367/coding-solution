
/*
    name= shortest common supersequence
    link- https://leetcode.com/problems/shortest-common-supersequence/submissions/
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1- take help of longest common subsequence;
*/




class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int a= str1.length();
        int b= str2.length();
        int dp[a+1][b+1];
        for(int i=0;i<a+1;i++)dp[i][0]=0;
        for(int i=0;i<b+1;i++)dp[0][i]=0;
        
        for(int i=1;i<a+1;i++)
        {
            for(int j=1;j<b+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]= 1+ dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans;
        int n=a,m=b;
        while(n>0 && m>0)
        {
            
            if(str1[n-1]==str2[m-1])
            {    
                ans.push_back(str1[n-1]);
                n--;
                m--;
            }
            else if(dp[n-1][m]<dp[n][m-1])
            {
                ans.push_back(str2[m-1]);
                m--;
            }
            else
            {
                ans.push_back(str1[n-1]);
                n--;
            }
           
        }
        
        while(n>0)
        {
            ans.push_back(str1[n-1]);
            n--;
        }
        while(m>0)
        {
            ans.push_back(str2[m-1]);
            m--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};