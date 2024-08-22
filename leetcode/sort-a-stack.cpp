/*
    name= sort a stack
    link- https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
    author- Parth garg
    time complexity- o(n^2)
    space complexity- o(n)
    method 1;
*/

#include <bits/stdc++.h> 
using namespace std;
void sortRecursive(stack<int> &st)
{
    if(st.empty()) return;
    
    int topelement= st.top();
    st.pop();
    
    sortRecursive(st);
    
    stack <int> tempStack;
    while( !st.empty() && st.top() >topelement )
    {
        tempStack.push(st.top());
        st.pop();
    }
    st.push(topelement);
    while(!tempStack.empty())
    {
        st.push(tempStack.top());
        tempStack.pop();
    }

}

void sortStack(stack<int> &st)
{
	sortRecursive(st);
    
}