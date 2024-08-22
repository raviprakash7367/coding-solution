/*
    name= First and last occurrences of x
    link-  https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(1)
    method 1;
*/


vector<int> find(int arr[], int n , int x )
{
    int i= 0,j= n-1;
    vector<int>v(2);
    while(i<j){
        int mid= i+ (j-i)/2;
        if(arr[mid]>= x) j= mid;
        else i=mid+1;
    }
    if(arr[j] != x) return {-1,-1};
    v[0] = j;
    
    i=j;j= n-1;
    while(i<j){
        int mid = i+(j-i+1)/2;
        if(arr[mid]<= x) i= mid;
        else{
            j= mid-1;
        }
    }
    v[1] = i;
    return v;
    
}