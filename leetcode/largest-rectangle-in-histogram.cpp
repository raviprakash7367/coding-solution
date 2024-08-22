/*
    name= largest rectangle in histogram
    link- https://leetcode.com/problems/largest-rectangle-in-histogram/description/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- take the help of stack for storing left min index and right min index;
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int ans= 0;
        vector<int>left(n),right(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                left[i]= 0;
            }
            else{
                left[i]= st.top()+1;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                right[i]= n-1;
            }
            else{
                right[i]= st.top()-1;
            }
            st.push(i);
        }

        for(int i=0;i<n;i++){
            ans= max(ans, heights[i]*(right[i]-left[i] +1 ));
        }
        
        return ans;

    }
};