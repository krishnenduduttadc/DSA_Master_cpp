
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

void print(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

void reorderList(Node *head)
{
    if (!head || !head->next)
        return;
    // middle find
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // reverse second part
    Node *prev = nullptr;
    Node *curr = slow;
    while (curr)
    {
        Node *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    //Merge
    Node* first=head;
    Node* second=prev;

    while(second->next){
        Node* tmp1 = first->next;
        Node* tmp2 = second->next;
        first->next=second;
        second->next=tmp1;
        first=tmp1;
        second=tmp2;
    }
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

    Node *head = createLinkedList(arr, n);
    print(head);
    reorderList(head);
    cout<<"reordered";
    print(head);
}