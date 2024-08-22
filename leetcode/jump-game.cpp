/*
    name= junp game
    link- https://leetcode.com/problems/jump-game/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int x;
        int max=0;
        for(int i=0;i<n;i++)
        {
            if(max< i) return false;
            x= i+ nums[i];
            if(x>max) max= x;   
        }
        return true;
    }
};