/*
    name= https://leetcode.com/problems/minimize-maximum-of-array/description/
    link- minimize-maximum-of-array
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1
            we can solve this using binary search 
            it is clear that we can do the following operation :
                decrease nums[i] by 1
                increase nums[j] by 1 where j < i 
            so if we want a value x can be possible or not then try making every value
            less than equal to x.

            let arr= {a,b,c,d,e, . . . . . }
            and we i is index 4 (e) 
            then a+b+c+d+e <= x+x+x+x+x

            general formula = prefixSum(i) <= (i+1) * x  
            TC for this algo is o(nlog(1e9));
            
    method- 2
            now try to find the value of x using above formula which is 
            x >= prefixSum[i]/(i+1) 
            for every index calculate x and the maximum one will be the answer
        
*/

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int x;
        int ans= INT_MIN;
        long long prefixSum=0;
        for(int i=0;i<nums.size();i++)
        {
            prefixSum += nums[i];
            x = ceil((double)prefixSum/(i+1));
            ans= max(ans, x);
        }
        return ans;
    }
};