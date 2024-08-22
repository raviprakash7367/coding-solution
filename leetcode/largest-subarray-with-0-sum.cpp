/*
    name= largest subarray with 0 sum
    link- https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/



class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int arr[n+1];
        arr[0]=0;
        for(int i=1;i<n+1;i++)
        {
            arr[i]= arr[i-1]+A[i-1];
        }
        int ans=0,x=0;
        unordered_map<int,int>m;
        for(int i=1;i<n+1;i++)
        {
            if(m.find(arr[i])== m.end()) m[arr[i]]= i;
            else
            {
                x= i-m[arr[i]];
                ans= max(x,ans);
            }
            if(arr[i]==0)
            {
                ans= i;
            }
            // cout<<ans<<endl;
        }
        return ans;
        
    }
};
