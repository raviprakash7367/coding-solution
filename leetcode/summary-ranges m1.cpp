
/*
    Name- summary ranges
    link- https://leetcode.com/problems/summary-ranges/submissions/
    author-Parth garg
    time complexity- o(n^2)
    method 1- check diff. of 2 consecutive elements and use to_string function to convert integer to string
*/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0,j=0;
        vector<string>subStr;
        string s;
        
        for(;i<nums.size();i++)
        {
            for(j=i;j<nums.size()-1;j++)
            {
                long long consecutiveDiff= (long long)nums[j+1]-(long long)nums[j];
                if(consecutiveDiff != 1) break;
            }
            s.clear();
            if(i== nums.size()-1)  s= to_string(nums[i]);
            else if(i!=j)  s= to_string(nums[i])+"->"+to_string(nums[j]);
            else if(i==j)  s= to_string(nums[i]);
            
            subStr.push_back(s); 
            
            i=j;            
        }
        return subStr;
    }
};