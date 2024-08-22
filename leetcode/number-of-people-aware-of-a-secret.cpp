/*
    name= Number of People Aware of a Secret
    link- https://leetcode.com/problems/number-of-people-aware-of-a-secret/
    author- Parth garg
    time complexity-o(n)
    space complexity- o(n)
    method 1- delayFreq = no. of persons who are in delay state at that index,
              forgetFreq= no. of persons who forget the secret at that index;
*/



class Solution {
public:
    const unsigned int m = 1000000007;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        long long dp[n+1];
        long long forgetFreq=0,delayFreq=1;
        long long newcomers[n+1];
        dp[1]= 1;
        newcomers[1]=1;
        for(int i=2;i<n+1;i++)
        {
            if(i-delay>= 1)
            delayFreq = ((delayFreq%m) - (newcomers[i-delay]%m)+m)%m;
            
            if(i-forget>=1)
            forgetFreq= newcomers[i-forget]%m;
            
            dp[i]= (((((((dp[i-1]%m)- forgetFreq%m+m)%m- (delayFreq)%m)*2)+m)%m) +delayFreq%m)%m; 
            
            newcomers[i]= ((dp[i-1]%m- forgetFreq%m- delayFreq%m)+m)%m;
            
            delayFreq=(delayFreq%m+ newcomers[i]%m)%m;
            
        }
        return dp[n]%m;
    }
};