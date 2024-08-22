/*
    name= Maximum difference of zeros and ones in binary string
    link- https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

class Solution{
public:	
	int maxSubstring(string S)
	{
	    int ans= -1;
	    int x= 0;
	    for(int i=0;i<S.size();i++){
	        if(S[i]== '1'){
	            x= max(0,x-1);
	        }
	        else{
	            x++;
	        }
	        ans= max(ans, x);
	    }
	    return (ans<=0) ? -1 : ans; 
	}
};