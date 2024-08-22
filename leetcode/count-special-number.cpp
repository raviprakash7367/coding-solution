/*
    name=  Count Special Numbers
    link- https://practice.geeksforgeeks.org/problems/3d49e4cce2820a813da02d1587c2dd9c542ce769/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(nlogn)
    method 1;
*/

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        unordered_map<int,int>mp;
        for(auto val :arr){
            mp[val]++;
        }
        if(mp[1] >1) return N;
        else if(mp[1]==1) return N-1;
        
        sort(arr.begin(),arr.end());
        int count= 0;
        for(int i=0;i<N;i++){
            if(mp[arr[i]]>1){
                count += mp[arr[i]];
                i+= (mp[arr[i]] -1);
                continue;
            }
            for(int j= 1; j< arr[i] ; j++){
                if(arr[i]%j ==0){
                    if((mp[j]==1 && arr[i]!= j) || mp[j]>1) {
                        count++;
                        break;
                    }
                }
            }
            
        }
        return count;
    }
};
