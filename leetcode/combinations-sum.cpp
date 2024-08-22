/*
    name= combinations-sum
    link- https://leetcode.com/problems/combination-sum/description/
    author- Parth garg
    time complexity- O(2^t * k) where t is the target, k is the average length
    space complexity- O(k*x), k is the average length and x is the no. of combinations
    method 1;
*/



class Solution {
public:
    vector<vector<int>>result;
    void combinations(vector<int> &candidates, int w, int i, vector<int>& temp)
    {
        if(i== candidates.size())
        {
            if(w==0)
            {
                result.push_back(temp);
            }
            return;
        }

        if(candidates[i]<=w)
        {
            temp.push_back(candidates[i]);
            combinations(candidates, w-candidates[i],i,temp);

            temp.pop_back();
            combinations(candidates,w,i+1,temp);
        }
        else
        {
            combinations(candidates,w,i+1,temp);
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        combinations(candidates,target, 0,temp);
        return result;
    }
};