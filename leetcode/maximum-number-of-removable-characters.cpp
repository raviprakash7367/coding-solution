/*
    name= https://leetcode.com/problems/maximum-number-of-removable-characters/description/
    link- maximum-number-of-removable-characters
    author- Parth garg
    time complexity- o(nlog m ) n= length of s and m = removable.length()
    space complexity- o(n)
    method 1;
*/
class Solution {
public:

    bool check(string &s, string &p, vector<int>&removable, int k){
        string s1= s;
        int n= s.length();
        for(int i=0;i<k;i++){
            s1[removable[i]] = 'A';
        }
        for(int i=0,j=0;i<n;){
            if(s1[i] == p[j]){i++;j++;}
            else{i++;}

            if(j== p.length()) return true;
        }
        return false;
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l= 0 ,r= removable.size();
        
        while(l<r){
            int mid = l+ (r-l+1)/2;
            if(check(s,p,removable,mid)){
                l= mid;
            }
            else{
                r= mid-1;
            }
        }
        return l;
    }
};