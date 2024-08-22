/*
    name= maximum length
    link- https://practice.geeksforgeeks.org/problems/84963d7b5b84aa24f7807d86e672d0f97f41a4b5/1
    author- Parth garg
    time complexity- o(1)
    space complexity- o(1)
    method 1;
*/
class Solution {
public:
    int solve(int a, int b, int c) {
        if(a==b && b==c) return a+b+c;
        else{
            vector<int>v(3);
            v[0]= a;v[1]=b;v[2]=c;
            sort(v.begin(),v.end());
            if(((v[2]-1)/2) > (v[0]+v[1])){
                return -1;
            }
            else{
                return a+b+c;
            }
        }
    }
};