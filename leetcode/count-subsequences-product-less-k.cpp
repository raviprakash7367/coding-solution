


#include<bits/stdc++.h>
using namespace std;

int productSubSeqCount(int arr[], int n,int k){
    if(n==0) return 0;

    int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<k+1;i++){
        for(int j=1;j<n+1;j++)
        {
            dp[i][j] = dp[i][j-1];
            if(i >= arr[j-1]){
                dp[i][j]+= dp[i/arr[j-1]][j-1] +1;
            }
        }
    }
    return dp[k][n];
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<productSubSeqCount(arr, n,k)<<endl;
}