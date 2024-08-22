/*
    name= construct binary tree from string with bracket representation
    link- https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/


class Solution{
public:
    Node* constructTree( string &s,int *start){
        if(s.size()==0 || *start >= s.size()) return NULL;
        
        string num="";
        while(*start < s.size() && s[*start] != '(' && s[*start] != ')'){
            num+= s[*start];
            *start= *start+1;
        }
        int rootData = stoi(num);
        
        Node *newNode= NULL;
        if(rootData >0 ) newNode= new Node(rootData);
        
        
        if(*start<s.size() && s[*start]=='('){
            *start= *start+1;
            newNode->left= constructTree(s, start);
        }
        if(*start < s.size() && s[*start]==')'){
            *start= *start+1;
            return newNode;
        }
        
        if(*start < s.size() && s[*start]== '('){
            *start= *start+1;
            newNode->right= constructTree(s, start);
        }
        if(*start < s.size() && s[*start]==')'){
            *start= *start+1;
        }
        return newNode;

    }
    
    Node *treeFromString(string str){
        if(str.length()==0) return NULL;
        int start= 0;
        return constructTree(str, &start);
        
    }
};