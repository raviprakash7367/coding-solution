
/*
    name= construct binary tree from string with bracket representation
    link- https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n)
    method 1;
*/

class Solution{
public:
    Node* constructTree( string &s,int l,int r){
        if(r<l) return NULL;
        
        string num="";
        while(l<=r && s[l] != '(' ){
            num+= s[l];
            l++;
        }
        int rootData = stoi(num);
        Node *newNode= new Node(rootData);
        
        int ptr=l;
        stack<char>st;
        for(int i= l;i<=r;i++){
            if(s[i]=='(') st.push('(');
            else if(s[i]== ')') st.pop();
            if(st.empty()) {
                ptr= i;
                break;
            }
        }
        
        newNode->left= constructTree(s, l+1,ptr-1);
        newNode->right= constructTree(s, ptr+2, r-1);
        return newNode;

    }
    
    Node *treeFromString(string str){
        if(str.length()==0) return NULL;
        return constructTree(str,0,str.length()-1);
        
    }
};