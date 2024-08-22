/*
    name= job sequencing problem 
    link- https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 2; using set in place of hash array
*/


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(struct Job a, struct Job b){
        if(a.profit != b.profit)return a.profit > b.profit ;
        else{
            return a.dead > b.dead;
        }
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n, comp);
        
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i].dead >m) m= arr[i].dead;
        }
        set<int,greater<int>>s;
        for(int i=1;i<=m;i++){
            s.insert(i);
        }
        
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            int deadline= arr[i].dead;
            
            auto it= s.lower_bound(deadline);
            if(it == s.end())continue;
            else{
                s.erase(it);
                sum+= (arr[i].profit);
                count++;
            }
        }
        return {count, sum};
        
    } 
};