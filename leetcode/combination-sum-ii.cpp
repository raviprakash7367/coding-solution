/*
    name= Combination Sum II
    link- https://leetcode.com/problems/combination-sum-ii/description/
    author- Parth garg
    time complexity- O(2^n*k)
    space complexity- O(k*x)
    method 1;
*/

class Solution {
public:
    vector<vector<int>>result;
    void findCombinations(vector<int>& candidates, int w,int i ,vector<int>&temp)
    {
        if(w==0)
        {
            result.push_back(temp);
            return;
        }

        for(int k= i; k<candidates.size();k++)
        {
            if(k > i && candidates[k] == candidates[k-1]) continue;
            if(candidates[k]> w) break;
            temp.push_back(candidates[k]);
            findCombinations(candidates,w-candidates[k],k+1,temp);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        findCombinations(candidates,target,0,temp);
        
        return result;
    }
};