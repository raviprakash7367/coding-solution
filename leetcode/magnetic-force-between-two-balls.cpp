/*
    name= magnetic force between two balls
    link- https://leetcode.com/problems/magnetic-force-between-two-balls/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    bool check(vector<int>&position, int m , int x){
        int prev= 0;m--;
        for(int i=1;i<position.size();i++){
            if(position[i]- position[prev] >= x){
                m--;
                prev= i;
                if(m==0) return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=0,r= position.back();
        while(l<r){
            int mid = l+ (r-l+1)/2;
            if(!check(position,m,mid)){
                r= mid-1;
            }
            else{
                l= mid;
            }
        }
        return l;
    }
};