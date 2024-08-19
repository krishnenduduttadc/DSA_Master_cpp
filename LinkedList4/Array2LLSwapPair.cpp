
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

Node *swapPairs(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *newhead = head->next;
    Node *prev = nullptr;

    while (head && head->next)
    {
        Node *first = head;
        Node *second = head->next;

        first->next = second->next;
        second->next = first;

        if (prev)
        {
            prev->next = second;
        }
        prev = first;
        head = first->next;
    }
    return newhead;
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

    cout << "Swapped";
    Node *nhead = swapPairs(head);
    print(nhead);
}