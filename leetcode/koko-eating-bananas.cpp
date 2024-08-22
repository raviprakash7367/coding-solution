/*
    name= Koko Eating Bananas
    link- https://leetcode.com/problems/koko-eating-bananas/description/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx= INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>mx)mx= piles[i];
        }
        int l=1,r=mx;
        while(l<r){
            int mid= l+ (r-l)/2;
            int count =0 ;
            for(int i=0;i<piles.size();i++){
                count+= piles[i]/mid;
                if(piles[i]%mid != 0) count++;
            }
            // cout<<count<<endl;
            if(count>h){
                l= mid+1;
            }
            else{
                r= mid;
            }
        }
        return l;
    }
};