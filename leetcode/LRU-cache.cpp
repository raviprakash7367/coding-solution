/*
    name= LRU cache
    link- https://leetcode.com/problems/lru-cache/description/
    author- Parth garg
    time complexity- o(1)
    space complexity- o(n)
    method 1- use hashmap, doubly linked list;
*/

class LRUCache {
public:
    
    class node{
    public: 
        int key;
        int value;
        node *next;
        node *prev;

        node(int _key, int _val)
        {
            key= _key;
            value= _val;
            next= NULL;
            prev= NULL;
        }
    };

    int size;
    node *head= new node(0,0);
    node *tail= new node(0,0);

    unordered_map<int, node*> m;

    void addnode(node *newnode)
    {
        node *nextNode= head->next;
        head->next= newnode;
        nextNode->prev= newnode;
        newnode->prev= head;
        newnode->next= nextNode;
    }

    void deletenode(node *newNode)
    {
        node *prevNode= newNode->prev;
        node *nextNode= newNode->next;
        prevNode->next= nextNode;
        nextNode->prev= prevNode;
    }

    LRUCache(int capacity) {
        size=capacity;
        head->next= tail;
        head->prev= NULL;
        tail->next= NULL;
        tail->prev= head;
    }
    

    int get(int key) {
        if(m.find(key)== m.end()) return -1;
        else
        {
            node *getNode= m[key];
            int data= getNode->value;
            deletenode(getNode);
            addnode(getNode);
            return data;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key)!= m.end())
        {
            node *newNode= m[key];
            newNode->value= value;
            deletenode(newNode);
            addnode(newNode);
        }
        else
        {
            if(m.size()<size)
            {
                
                node *newNode= new node(key,value);
                addnode(newNode);
                m[key]= newNode;
            }
            else
            {
                node *newNode= new node(key,value);
                m.erase(tail->prev->key);
                deletenode(tail->prev);
                m[key]= newNode;
                addnode(newNode);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */