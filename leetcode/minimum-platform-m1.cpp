/*
    name= Minimum Platforms
    link- https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
    author- Parth garg
    time complexity- o(n logn)
    space complexity- o(n)
    method 1;
*/



int findPlatform(int arr[], int dep[], int n)
    {
        
    	priority_queue<int, vector<int>, greater<int>> s;
    	vector<pair<int,int>>v;
    	for(int i=0; i< n;i++)
    	{
    	    v.push_back({arr[i],dep[i]});
    	}
    	sort(v.begin(),v.end());
    	
    	int count=1;
    	s.push(v[0].second);
    	
    	for(int i=1;i<n;i++)
    	{
    	    if(v[i].first <= s.top())
    	    {
    	        s.push(v[i].second);
    	    }
    	    else if( v[i].first > s.top() )
    	    {
    	        
    	        while(s.size()!= 0 && s.top() < v[i].first )
    	        {
    	            s.pop();
    	        }
    	        s.push(v[i].second);
    	    }
    	    
    	    if(count<s.size())
    	       count = s.size();
    	}
    	return count;
    }