/*  
    name- find the duplicate number
    link-https://leetcode.com/problems/find-the-duplicate-number/
    author-Parth garg
    time complexity- o(n)
    method 1- using set for hashing
    // we can use hash array also...
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            int oldSize= s.size();
            s.insert(nums[i]);
            int newSize= s.size();
            if(newSize==oldSize) return nums[i];
        }
        return 0;
    }
};