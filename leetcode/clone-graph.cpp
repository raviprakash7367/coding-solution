/*
    name= clone graph
    link- https://leetcode.com/problems/clone-graph/description/
    author- Parth garg
    time complexity- o(2*(v+2e)) = o(v+e)
    space complexity- o(v)
    method 1;
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *node , map<Node*, int>&vis,map<int,Node*>&mp){
        if(node == NULL) return;
        vis[node] = 1;
        Node* newNode = new Node(node->val);
        mp[node->val] = newNode;
        for(auto child : node->neighbors){
            if(vis[child] == 0){
                dfs(child, vis,mp);
            }
        }
    }

    void dfs2(Node *node,map<Node*, int>&vis,map<int,Node*>&mp ){
        if(node == NULL) return;
        vis[node] = 2;
        vector<Node*>clonedNeighbor;
        Node* currNode = mp[node->val];
        for(auto child : node->neighbors){
            if(vis[child] != 2){
                dfs2(child,vis,mp);
            }
            clonedNeighbor.push_back(mp[child->val]);
        }
        currNode->neighbors= clonedNeighbor;
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        map<int,Node*>mp;
        map<Node*, int>vis;
        dfs(node, vis,mp);
        dfs2(node, vis,mp);
        Node* res = mp[node->val];
        
        return res;
    }
};
