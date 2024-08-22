/*
    name= boats to save people
    link- https://leetcode.com/problems/boats-to-save-people/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count =0;
        int l=0,r= people.size()-1;
        while(l<=r){
            if(l==r){count++;break;}
            if(people[l]+people[r] <= limit){
                l++;
                r--;
                count++;
            }
            else{
                r--;
                count++;
            }
        }
        return count;
    }
};