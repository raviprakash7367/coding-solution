/*
    name= Minimum Time to Repair Cars
    link- https://leetcode.com/problems/minimum-time-to-repair-cars/
    author- Parth garg
    time complexity- o(nlog m )  (m is of range long long) 
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    
    bool findCount(long long time, vector<int>&ranks,int& C){
        long long count=0;
        for(int i=0;i<ranks.size();i++){
            long long temp = time/ranks[i];
            long long t=  floor(sqrtl(temp));
            count+= t;
            
        }
        return (count>=C);
    }
    
    long long repairCars(vector<int>& ranks, int C) {
        int n= ranks.size();
        
        long long l= 1,r= 1e14;
        while(l<r){
            long long mid = (l+r)/2;
            
            if(findCount(mid,ranks,C)){
                r= mid;
            }
            else{
                l= mid+1;
            } 
        }
        return l;
        
    }
};