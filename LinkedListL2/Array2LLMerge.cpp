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

Node *mergeTwoLists(Node *head1, Node *head2)
{
    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (head1 && head2)
    {
        if (head1->data >= head2->data)
        {
            tail->next = head2;
            head2 = head2->next;
        }
        else if (head1->data < head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        tail = tail->next;
    }
    tail->next = head1 ? head1 : head2;
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    int arr1[n];
    int arr2[n];
    cout << "first\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "second\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    Node *head1 = createLinkedList(arr1, n);
    print(head1);

    Node *head2 = createLinkedList(arr2, n);
    print(head2);

    Node *resNode = mergeTwoLists(head1, head2);
    cout << "Resulting LL head is :" << resNode->data << endl;
    print(resNode);
}