/*
    name- reverse-vowels-of-a-string
    link- https://leetcode.com/problems/reverse-vowels-of-a-string/
    author- parth garg
    time complexity- o(n)
    method 1- use 2 pointers and flag for checking if element is vowel or not
*/


class Solution {
public:
    string reverseVowels(string s) {
        int lt=0,rt= s.length()-1;
        while(lt<rt){
            bool l= false,r=false;
            if(s[lt]=='a'||s[lt]=='e'||s[lt]=='i'||s[lt]=='o'||s[lt]=='u'||s[lt]=='A'||s[lt]=='E'||s[lt]=='I'||s[lt]=='O'||s[lt]=='U'){
                l= true;
            }
            if(s[rt]=='a'||s[rt]=='e'||s[rt]=='i'||s[rt]=='o'||s[rt]=='u'||s[rt]=='A'||s[rt]=='E'||s[rt]=='I'||s[rt]=='O'||s[rt]=='U'){
                r= true;
            }
            if(l && r){
                swap(s[lt],s[rt]);
                lt++;rt--;
            }
            if(l==false) lt++;
            if(r==false) rt--;
            
        }
        return s;
    }
};