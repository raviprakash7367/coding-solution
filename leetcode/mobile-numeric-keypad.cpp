/*
    name= mobile numeric keypad
    link- https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

class Solution{
	public:
	long long getCount(int N)
	{
	    if(N==1) return 10;
		vector<long long>curr(10,1), next(10);
		
		for(int i=2;i<=N;i++){
		    next[0]= curr[0]+curr[8]; 
		    next[1]= curr[1]+curr[2]+curr[4];
		    next[2]= curr[2]+curr[1]+curr[3]+curr[5];
		    next[3]= curr[3]+curr[2]+curr[6];
		    next[4]= curr[4]+curr[1]+curr[7]+curr[5];
		    next[5]= curr[5]+curr[2]+curr[4]+curr[6]+curr[8];
		    next[6]= curr[6]+curr[3]+curr[9]+curr[5];
		    next[7]= curr[7]+curr[4]+curr[8];
		    next[8]= curr[8]+curr[0]+curr[5]+curr[7]+curr[9];
		    next[9]= curr[9]+curr[6]+curr[8];
		    curr= next;
		}
		long long ans=0;
		for(int i=0;i<10;i++){
		    ans+= curr[i];
		}
		return ans;
	}
};