/*
    name= add to array form of integer
    link- https://leetcode.com/problems/add-to-array-form-of-integer/
    author- Parth garg
    time complexity- o(n)
    method 1;
*/

//method 1 - using extra vector for storing result
//space complexity- o(n)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>v;
        int n= num.size();
        int carry= 0;
        for(int i=n-1;i>=0;i--){
            int sum= num[i]+ (k%10) +carry;
            carry= sum/10;
            v.push_back(sum%10);
            k/=10;
        }
        while(k>0){
            int sum= (k%10)+carry;
            carry = sum/10;
            k/=10;
            v.push_back(sum%10);
        }
        if(carry !=0) v.push_back(carry);
        reverse(v.begin(),v.end());
        return v;
    }
};


//method 2 - inserting element in front of the vector 
//time complexity of inserting element is o(n) 
//space complexity- o(1)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        for(int i=num.size()-1; i>=0; i--){
            int n=num[i]+carry+k%10;
            carry=0;
            num[i]=n%10;
            carry=n/10;
            k/=10;
            if(k==0 && carry==0){break;}
        }
        while(k){
            int val=k%10+carry;
            carry=val/10;
            num.insert(num.begin(), val%10);
            k/=10;
        }
        if(carry){
            num.insert(num.begin(), carry);
        }
        return num;
    }
};

