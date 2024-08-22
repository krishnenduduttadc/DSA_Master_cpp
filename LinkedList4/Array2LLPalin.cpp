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

bool isPalindrome(Node* head) {
    stack<int> s;
    Node* current=head;
    while(current){
        s.push(current->data);
        current=current->next;
    }
    current=head;
    while(current){
        if(current->data!=s.top()){
            return false;
        }
        s.pop();
        current=current->next;
    }
    return true;
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

    if (isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }
}