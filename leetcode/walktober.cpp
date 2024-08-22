/*
    name= walktober
    link- https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb2e1/0000000000c174f2
    author- Parth garg
    time complexity- o(m*n)
    space complexity-o(m*n)
    method 1;
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(i, n) for (int32_t i = 0; i < int32_t(n); i++)

int32_t main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int m,n,p;
        cin>>m>>n>>p;
        int arr[m][n];
        
        int ans= 0;
        fori(i,m)
        {
            fori(j,n)
            {
                cin>>arr[i][j];
            }
        }

        fori(j,n)
        {
            int max= INT_MIN;
            fori(i,m)
            {
                if(arr[i][j]>max) max= arr[i][j];
            }
            ans = ans + (max-arr[p-1][j]);
        }
        cout<<"Case #"<<z<<": "<<ans<<endl;
    }
}