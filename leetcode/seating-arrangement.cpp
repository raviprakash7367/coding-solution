/*
    name= seating arrangement
    link- https://practice.geeksforgeeks.org/problems/6bb49b563cc171335c6564b00307a6d867e0268d/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/
class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& s){
        for(int i=0;i<m;i++){
            if(s[i]==0){
                if(i==0 && ((i+1 <m &&  s[i+1]==0) || (i+1 >=m))){
                    n--;
                    i++;
                }
                else if(i+1 <m && s[i+1] == 0 && s[i-1] == 0 ){
                    n--;
                    i++;
                }
                else if(i+1 == m && s[i-1]==0){
                    n--;
                    i++;
                }
            }
            else{
                i++;
            }
            if(n<=0) return true; 
        }
        return false;
    }
};