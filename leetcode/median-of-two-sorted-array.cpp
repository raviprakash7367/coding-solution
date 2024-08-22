/*
    name= median of two sorted arrays
    link- https://leetcode.com/problems/median-of-two-sorted-arrays/description/
    author- Parth garg
    time complexity- o(log(min(n,m)));
    space complexity- o(1)
    method 1- cut length from array 1 and cut k-length from array 2 and then check the
        conditions if it is write cut or not according to that change the left and
        right pointer and update the cut1 and cut2;
*/


class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size(),m= nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int k= (n+m+1)/2;
        int l=0;
        int r= n;
        int cut1,cut2;

        while(l<=r)
        {
            cut1= (l+r)/2;
            cut2= (k- cut1);

            int l1= (cut1== 0)? INT_MIN: nums1[cut1-1];
            int l2= (cut2== 0)? INT_MIN: nums2[cut2-1];
            int r1= (cut1== n)? INT_MAX: nums1[cut1];
            int r2= (cut2== m)? INT_MAX: nums2[cut2];

            if(l1>r2)
            {
                r= cut1-1;
            }
            else if(l2>r1)
            {
                l= cut1+1;
            }
            else
            {
                if((m+n)%2 ==0) return (max(l1,l2)+ min(r1,r2))/2.0;
                else return max(l1,l2);
            }
        }
        return 0;
    }
};