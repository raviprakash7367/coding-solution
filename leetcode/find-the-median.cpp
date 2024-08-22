/*
    name= Find the median
    link-  https://practice.geeksforgeeks.org/problems/find-the-median0527/1
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1-sort;
*/




class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(),v.end());
		    if(v.size()%2==1)
		        return v[v.size()/2] ;
		    else 
		        return (v[v.size()/2] + v[(v.size()/2)-1] )/2;
		}
};