/*
    name= minimum number of jumps
    link- https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

class Solution{
  public:
    int minJumps(int arr[], int n){
        int halt= 0;
        int maxidx=0;
        int jump=0;
        if(arr[0]==0) return -1;
        for(int i=0;i<n-1;i++){
            maxidx = max(maxidx, i+arr[i]);
            if(i== maxidx) return -1;
            if(maxidx >= n-1){
                jump++;
                return jump;
            }
            if(i == halt){
                halt= maxidx;
                jump++;
            }
        }
        if(halt>= n-1){
            return jump;
        }
        else return -1;
    }
};