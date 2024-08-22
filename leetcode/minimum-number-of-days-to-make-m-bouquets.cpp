/*
    name= Minimum Number of Days to Make m Bouquets
    link- https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
    author- Parth garg
    time complexity-  o(nlogn)
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    bool check(vector<int>&bloomDay, int m , int k, int mid){
        int count = 0;
        int n= bloomDay.size();
        for(int i=0;i<n;i++){
            int temp= 0;
            while(i<n && bloomDay[i] <= mid){
                i++;
                temp++;
            }
            count+= (temp/k) ;
        }
        return count >= m ;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int r= INT_MIN,l=1;
        int n= bloomDay.size();
        if(k*1LL*m > n) return -1;
        for(int i=0;i<n;i++){
            if(bloomDay[i]> r) r= bloomDay[i];
        }

        while(l<r){
            int mid = l + (r-l)/2;
            if(check(bloomDay, m,k,mid)){
                r= mid;
            }
            else{
                l= mid+1;
            }
        }
        return l;
    }
};