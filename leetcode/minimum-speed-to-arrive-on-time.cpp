/*
    name= https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
    link- minimum-speed-to-arrive-on-time
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1;
*/
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= dist.size()-1) return -1;
        int l= 1,r= 1e9;
        while(l<r){
            int mid = l+ (r-l)/2;
            double reqHours= 0;
            for(int i=0;i<dist.size()-1;i++){
                reqHours+= ceil((float)dist[i]/mid);
            }
            reqHours+= ((double)dist.back()/mid);

            if(reqHours > hour){
                l= mid+1;
            }
            else{
                r= mid;
            }
        }
        return l;
    }
};