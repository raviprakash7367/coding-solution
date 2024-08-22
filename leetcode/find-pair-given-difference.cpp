/*
    name= Find Pair Given Difference
    link-  https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1
    author- Parth garg
    time complexity- o(size log size)
    space complexity- o(1)
    method 1;
*/

bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    int i=0,j=0;
    while(j<size && i<size){
        if(i==j){j++;continue;}
        if(arr[j]-arr[i] < n){
            j++;
        }
        else if(arr[j]-arr[i] > n){
            i++;
        }
        else{
            return true;
        }
    }
    return false;
    
}