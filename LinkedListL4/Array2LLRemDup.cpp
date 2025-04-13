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
Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    while (curr && curr->next)
    {
        if (curr->data == curr->next->data)
        {
            Node *tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
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

    Node *nhead = removeDuplicates(head);
    print(nhead);
}