/*
    name= N meetings in one room
    link-  https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
    author- Parth garg
    time complexity- O(N*LogN)
    space complexity- O(N)
    method 1;
*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        int count= 1;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
       
        sort(v.begin(),v.end());
        int prevEnd= v[0].second;
        
        for(int i= 1;i<n;i++)
        {
            if(v[i].first > prevEnd)
            {
                count++;
                prevEnd= v[i].second;
            }
            else if(v[i].second > prevEnd)
            {
                continue;
            }
            else
            {
                prevEnd= v[i].second;
            }
            
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends