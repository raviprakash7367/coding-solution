/*
    name= Job Sequencing Problem
    link- https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
    author- Parth garg
    time complexity- o(nlogn) + o(n*m)  {m= maximum deadline}
    space complexity- o(101)
    method 1 - sort according to profit ;
*/



//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    bool static comp(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        vector<int> slotsBooked(101,-1);
        int count=0;
        int maxProfit=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j= arr[i].dead; j>0; j--)
            {
                if(slotsBooked[j]== -1)
                {
                    slotsBooked[j]= i;
                    count++;
                    maxProfit+= arr[i].profit;
                    break;
                }
            }
        }
        vector<int>result= {count, maxProfit};
        return result;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends