/*
    ques name- add-binary
    link- https://leetcode.com/problems/add-binary/
    author- parth garg
    time complexity = o(n)
    method 1- add the carry, a[i],b[i] and update the carry and add 1/0 according to sum.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(i, n) for (int32_t i = 0; i < int32_t(n); i++)

int32_t main()
{
    string a;
    string b;
    cin>>a>>b;
    int sum=0;
        int carry=0;
        int i= a.length()-1;
        int j= b.length()-1;
        int idx= max(a.length(),b.length())-1;
        string s;
        while(idx>=0)
        {
            int x,y;
            sum=0;
            x= (i>=0)?a[i]-'0':0;
            y= (j>=0)?b[j]-'0':0;
            sum= x+y+carry;
            if(sum==0 || sum== 2)s+="0";
            else s+="1";
            
            carry= (sum>1)?1:0 ;
            cout<<i<<" "<<j<<endl;
            i--;j--;
            idx--;
        }
        if(carry==1)s+="1";
        reverse(s.begin(),s.end());
        cout<<s<<endl;
}