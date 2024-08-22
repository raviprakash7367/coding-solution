/*
    name= curling
    link- https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb2e1/0000000000c17c82
    author- Parth garg
    time complexity- o(n)
    space complexity-o(n)
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
        int ra,rb;
        double minR= INT_MAX,minY= INT_MAX;
        cin>>ra>>rb;
        int n,m;
        cin>>n;
        vector<double>red;
        vector<double>yellow;

        fori(i,n)
        {
            double x,y;
            cin>>x>>y;
            double dist= sqrt((x*x) + (y*y));
            if(dist<= rb+ra) 
            {
                red.push_back(dist);
                if(dist<minR) minR= dist;
            }
        }

        cin>>m;
        fori(i,m)
        {
            double x,y;
            cin>>x>>y;
            double dist= sqrt((x*x) + (y*y));
            if(dist<= rb+ra) 
            {
                yellow.push_back(dist);
                if(dist<minY) minY= dist;
            }
        }

        int ansR=0,ansY=0;
        if(red.size()==0 || yellow.size()==0 )
        {
            cout<<"Case #"<<z<<": "<<red.size()<<" "<<yellow.size()<<endl;
            continue;
        }
        
        if(minR>minY)
        {
            fori(i,yellow.size())
            if(yellow[i]<minR) ansY++;
        }
        else
        {
            fori(i,red.size())
            if(red[i]<minY) ansR++;
        }

        cout<<"Case #"<<z<<": "<<ansR<<" "<<ansY<<endl;
    }
}