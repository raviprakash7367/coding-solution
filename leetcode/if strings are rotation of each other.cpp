/*
    name- if strings are rotation of each other
    link- https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
    author- Parth garg
    time complexity- O(n^2)
    method 1: use substr for rotating the string
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!= s2.length())
    {
        cout<<"String are not rotation of each other"<<endl;
        return 0;
    }
    vector<int>index;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]==s2[0]) index.push_back(i);
    }
    for(int i=0;i<index.size();i++)
    {
        string rotated= s1.substr(index[i], s1.length()-index[i]) + s1.substr(0,index[i]);
        if(rotated== s2) 
        {
            cout<<"Strings are rotations of each other"<<endl;
            return 0;
        }
    }
    cout<<"Strings are not rotations of each other"<<endl;
    return 0;
}