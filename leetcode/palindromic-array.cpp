
/*
    name= palindromic array
    link- https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1
    author- Parth garg
    time complexity- o(10*n)
    space complexity- o(10)
    method 1;
*/




class Solution {
public:
    int PalinArray(int arr[], int n)
    {
    	int temp[10];
    	for(int i=0;i<n;i++)
    	{
    	    // finding digits and storing in vector
    	    int last=0;
    	    while(arr[i]!=0)
    	    {
    	        temp[last++]= arr[i]%10;
    	        arr[i]/=10;
    	    }
    	    //check palindrome
    	    int l=0,r= last-1;
    	    while(l<r)
    	    {
    	        if(temp[l++]!= temp[r--]) return 0;
    	    }
    	    
    	}
    	return 1;
    }
};