/*
    name= zigzag tree traversal
    link- https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
    author- Parth garg
    time complexity- o(N)
    space complexity- o(N)
    method 1;
*/


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        if(!root)return {};
        int level=0;
    	vector<int>zigZagTree;
    	queue<Node*>q;
    	q.push(root);
    	
    	while(!q.empty()){
    	    int i= zigZagTree.size();
    	    int n= q.size();
    	    for(int i=0;i<n;i++){
    	        if(q.front()->left) q.push(q.front()->left);
    	        if(q.front()->right) q.push(q.front()->right);
    	        zigZagTree.push_back(q.front()->data);
    	        q.pop();
    	    }
    	    if(level%2){
    	        reverse(zigZagTree.begin()+i, zigZagTree.end());
    	    }
    	    level++;
    	}
    	return zigZagTree;
    }
};