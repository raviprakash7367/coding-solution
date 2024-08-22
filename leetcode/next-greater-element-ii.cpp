/*
    name= next greater element-ii
    link- https://leetcode.com/problems/next-greater-element-ii/description/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- use stack and start from right;
*/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n= nums.size();
        s.push(nums[n-1]);
        vector<int>result(n);
        result[n-1]= -1;

        vector<int>temp;
        temp.push_back(n-1);
        for(int i=n-2;i>=0;i--)
        {
            if(s.size()>0 && nums[i] >= s.top())
            {
                while(s.size()>0 && s.top()<=nums[i])
                {
                    s.pop();
                }
                
                if(s.size()!=0)result[i] = s.top();
                else 
                {result[i]= -1;
                temp.push_back(i);}
                s.push(nums[i]);
            }
            else
            {
                result[i] = s.top();
                s.push(nums[i]);
            }
        }
        for(int i=0; i< temp.size();i++)
        {
            int pt= temp[i];
            while(s.size()>0 && s.top()<=nums[pt])
            {
                s.pop();
            }
            if(s.size()>0 && s.top()>nums[pt])result[pt]= s.top();
            
        }
        return result;
    }
};