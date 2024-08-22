/*
    name= stickler thief
    link- https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1; 
*/

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int FindMaxSum(int arr[], int n)
    {
        int pick,npick,prev1=arr[0],prev2=0,curr=0;
        
        for(int i=1;i<n;i++){
            
            pick = arr[i]+ prev2;
            npick= 0+ prev1;
            
            curr= max(pick, npick);
            prev2= prev1;
            prev1= curr;
        }
        
        return prev1;
    }
};