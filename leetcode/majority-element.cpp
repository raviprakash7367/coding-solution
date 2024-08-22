/*
    name= majority element
    link- https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        
        int count=1,maxi= a[0];
        for(int i=1;i<size;i++){
            if(a[i]== maxi){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                maxi= a[i];
                count=1;
            }
        }
        if(count > (size/2)){
            return maxi;
        }
        count=0;
        for(int i=0;i<size;i++){
            if(a[i]== maxi){
                count++;
            }
        }
        if(count> (size/2))return maxi;
        else return -1;
        
    }
};