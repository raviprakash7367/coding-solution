/*
    name= fireworks
    link- https://my.newtonschool.co/playground/code/98ecmlabam3m/
    author- Parth garg
    time complexity- o(200) approx
    space complexity- o(1)
    method 1- m= n/d(m)  check for all possible values of d(m); 
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(i, n) for (int32_t i = 0; i < int32_t(n); i++)

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=171;i++)
        {
            if(n%i==0)
            {
                int m= n/i;
                int sod=0;
                while(m!=0)
                {
                    sod+= m%10;
                    m/=10;
                }
                if(sod==i)
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}