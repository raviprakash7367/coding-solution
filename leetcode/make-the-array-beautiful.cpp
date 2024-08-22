/*
    name= make the array beautiful
    link- https://practice.geeksforgeeks.org/problems/badefd58bace4f2ca25267ccfe0c9dc844415e90/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- stack;
*/

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int>st;
        int i=0;
        while(i<arr.size()){
            if(!st.empty() && ((st.top()>= 0 && arr[i]<0) || (st.top() <0 && arr[i]>=0))){
                st.pop();
            }
            else{
                st.push(arr[i]);
            }
            i++;
        }
        int n= st.size();
        vector<int>res(n);
        for(int i= n-1;i>=0;i--){
            res[i]= st.top();
            st.pop();
        }
        return res;
    }
};