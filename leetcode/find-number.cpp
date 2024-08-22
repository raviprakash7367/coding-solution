/*
    name= find number
    link- https://practice.geeksforgeeks.org/problems/35bff0ee40090b092e97b02f649085bf1390cc67/1
    author- Parth garg
    time complexity- o(length of number)
    space complexity- o(1)
    method 1;
*/

class Solution{
public:
    long long findNumber(long long N){
        int arr[]= {1,3,5,7,9};
        int digits=0;
        long long temp= (4*N/5) +1;
        while(temp){
            digits++;
            temp/= 5;
        }
        long long num=0;
        vector<int>ans;
        while(N){
            int k= N%5;
            int idx= (k-1+5)%5;
            if(idx== 4) N--;
            N/= 5;
            ans.push_back(arr[idx]);
        }
        
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            num*= 10;
            num+= ans[i];
        }
        return num;
        
    }
};