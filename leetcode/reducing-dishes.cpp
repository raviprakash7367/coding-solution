/*
    name= reducing dishes
    link-  https://leetcode.com/problems/reducing-dishes/description/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1- binary search + memorisation;
*/

class Solution {
public:
    unordered_map<int,int>mp;
    int findSum(vector<int>&satisfaction , int i){
        if(mp[i] != 0) return mp[i];
        int sum=0;
        int t=1;
        for(int k= i ;k<satisfaction.size();k++){
            sum+= (t*satisfaction[k]);
            t++;
        }
        
        return mp[i]= sum;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n= satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int l= 0,r=n-1;
        while(l<r){
            int mid= l+ (r-l)/2;

            int sum = findSum(satisfaction,mid);
            int suml= mid!=0 ? findSum(satisfaction,mid-1) : 0;
            int sumr= findSum(satisfaction,mid+1);

            if(sumr > sum){
                l= mid+1;
            }
            //sumr <=sum     sum>= sumr
            else if(suml > sum){
                r= mid-1;
            }
            else{
                return sum>0 ? sum :0 ;
            }
            
        }
        int ans= findSum(satisfaction,l);
        return ans>0 ? ans :0 ;
    }
};