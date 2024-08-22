/*
    name= check mirro in N ary tree
    link- https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,stack<int>>m;
        
        for(int i=0;i<2*e;i+=2){
            m[A[i]].push(A[i+1]);
        }
        for(int i=0;i<2*e;i+=2){
            if(m[B[i]].top() != B[i+1]) return 0;
            else m[B[i]].pop();
        }
        return 1;
        
    }
};