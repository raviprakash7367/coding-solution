/*
    name= find missing and repeating
    link- https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        
        int missing,repeat;
        for(int i=0;i<n;i++){
            int x= abs(arr[i])-1;
            if(arr[x] <0 ){
                repeat= x+1;
            }
            else{
                arr[x] *= (-1);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                missing= i+1;
                break;
            }
        }
        int *ans;
        ans[0]= repeat;
        ans[1]= missing;
        return ans;
        
    }
};