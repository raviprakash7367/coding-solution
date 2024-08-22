/*
    name= Min Steps in Infinite Grid
    link- https://www.interviewbit.com/problems/min-steps-in-infinite-grid/?utm_medium=referral&utm_source=https://www.interviewbit.com/practice/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/



int Solution::coverPoints(vector<int> &arr1, vector<int> &arr2) {
    int count=0;
    int a=arr1[0],b=arr2[0];
    
    for(int i=1;i<arr1.size();i++)
    {
        int c= arr1[i],d= arr2[i];
        if(b==d)
        {
            count+= abs(c-a);
        }
        else if(c==a){
            count+= abs(b-d);
        }
        else
        {
            // int mini= min(abs(c-d),abs(d-b));
            int maxi= max(abs(c-a),abs(d-b));
            count+= maxi;
        }
        a=c;
        b=d;
    }
    return count;
}
