/* this is a circular linked list( single linked list) program in C++
insert, delete functions implemented */
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val) // constructor to create a node & allocate 
    {
        data = val;
        next = NULL;
    }
};
void insertAtHead(node* &head, int val) // insert elements at beginning
{
    node * n = new node(val);
    if(head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;

}
void insertTail(node* &head, int val) // insert the elements at end of the list
{
   node* n= new node(val);
    if(head ==NULL) // if heaad value is null
    {
        insertAtHead(head, val);
        return; // function to add node at head
    }
    node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;

}
void deleteFront(node* &head) // delete a node at the beginning
{
    node* temp = head;
    node * ptr = head;
    while(ptr->next != head)
    {
        ptr= ptr->next;
    }

    head = head->next;
    ptr->next = head;
    free(temp);
}
void deleteEnd(node* &head) // delete a node at the end
{
    node * temp = head;
    node* ptr;
    while(temp->next->next != head)
    {
        temp = temp->next;
    }
    ptr = temp->next;
    temp->next = head;  
    free(ptr); 

}
void display(node* head) // traverse the nodes or display the nodes
{
    node* temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while(temp != head); 
    cout << "NULL" <<endl;
}
int main()
{
    node* head = NULL;

    insertTail(head, 2); insertTail(head, 28); // inserting elements 2, 28,
    insertTail(head, 4); insertTail(head, 31); // 4, 31 at the end
    insertAtHead(head,18); insertAtHead(head, 8); //inserting 18, 8 at the head

    display(head); // printing the nodes
    deleteFront(head); // delete a node at head 
    display(head);
    deleteEnd(head); // delete a node at head
    display(head);

   // nodes data is  hardcoded
   // you can use " cin>> " to get values from terminal

return 0; 
}