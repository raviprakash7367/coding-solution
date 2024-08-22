/*
    name- sort the people
    link-https://leetcode.com/problems/sort-the-people/
    author- Parth garg
    time complexity-o(nlogn)
    space complexity- o(n)
    method 1- use hash map;
*/

class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
    map<int, string> m;
    vector<string>result;
    for (int i = 0; i < names.size(); i++)
    {
        m[heights[i]] = names[i];
    }
    for (auto it = m.begin(); it!= m.end();it++)
    {
        result.push_back(it->second);
    }
    reverse (result.begin(),result.end());
    return result;
}
};