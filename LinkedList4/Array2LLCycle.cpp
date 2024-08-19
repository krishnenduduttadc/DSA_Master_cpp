#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *curr = head;

    for (int i = 1; i < n; i++)
    {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

void print(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"nullptr"<<endl;

}

bool detectCycle(Node* head) {
    bool result=false;
    if (head == nullptr || head->next == nullptr) {
        return false; 
    }
    Node* fast=head;
    Node* slow=head;

    while(fast!=nullptr && fast->next!=nullptr ){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            result=true;
            return result;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node* head=createLinkedList(arr,n);
    print(head);
    bool res=detectCycle(head);
    cout<<res;
    cout<<"Cycle exists "<<res;
}