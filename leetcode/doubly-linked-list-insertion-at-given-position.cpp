/*
    name= doubly linked list insertion at given position
    link- https://practice.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list
    author- Parth garg
    time complexity- o(n)
    space complexity-o(1)
    method 1;
*/



/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
    Node* newNode= new Node(data);
    Node *temp= head;
   int count=0;
   while(count!= pos)
   {
       temp= temp->next;
       count++;
   }
   newNode->prev= temp;
   newNode->next= temp->next;
   temp->next= newNode;
   
}