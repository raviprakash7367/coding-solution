/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution
{
public:
    int findPairs(vector<int> &A, int B)
    {
        if (A.size() == 1)
            return 0;
        int n = A.size();
        sort(A.begin(), A.end());
        int l = 0, r = 1;
        int count = 0;
        while (r < n)
        {
            if (r > 1 && l > 0 && A[r] == A[r - 1] && A[l] == A[l - 1])
            {
                l++;
                r++;
                continue;
            }
            if (r == l || A[r] - A[l] < abs(B))
                r++;
            else if (A[r] - A[l] > abs(B))
                l++;
            else
            {
                count++;
                l++;
                r++;
            }
        }
        return count;
    }
};
// @lc code=end
