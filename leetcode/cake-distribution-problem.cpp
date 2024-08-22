/*
    name= cake distribution problem
    link- https://practice.geeksforgeeks.org/problems/0a7c7f1089932257071f9fa076f25d353f91e0fd/1
    author- Parth garg
    time complexity- o(n log M) M = sum of total sweetness
    space complexity- o(1)
    method 1- binary search;
*/

class Solution{
    public:
    bool check(vector<int>& sweetness, int N, int K, int mid){
        int left= N;
        int temp=0;
        for(int i=0;i<N;i++){
            temp+= sweetness[i];
            if(temp>=mid){
                temp=0;
                K--;
            }
            left= N-i-1;
            if(left < K){
                return false;
            }
        }
        return true;
    }
    
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        long long sum=0;
        for(int i=0;i<N;i++){
            sum+= sweetness[i];
        }
        
        long long l= 1,r= sum;
        while(l<r){
            long long mid = l+ (r-l+1)/2;
            if(check(sweetness, N, K+1, mid)){
                l= mid;
            }
            else{
                r= mid-1;
            }
        }
        return l;
    }
    
};