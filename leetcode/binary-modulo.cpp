/*
    name= binary modulo 
    link- https://practice.geeksforgeeks.org/problems/7488b7721e8aa5e5fc37d56af8b9c89e329c796f/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/
class Solution{
    public:
        int modulo(string s,int m)
        {
            if(m==1){
                return 0;
            }
            int x= 1;
            int ans;
            if(s.back()== '1'){
                ans = x;
            }
            else{
                ans = 0;
            }
            for(int i= s.length()-2;i>=0;i--){
                x= ((2%m) * x)%m;
                if(s[i]=='1'){
                    ans = (ans+ x)%m;
                }
            }
            return ans;
            
        }
};