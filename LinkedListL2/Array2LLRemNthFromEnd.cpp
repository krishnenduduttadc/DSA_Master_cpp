
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

Node *removeNthFromEnd(Node *head, int n)
{
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *fast = dummy;
    Node *slow = dummy;

    for (int i = 1; i <= n + 1; i++)
    {
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node* tmp=slow->next;
    slow->next=slow->next->next;
    delete tmp;
    return dummy->next;
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

    Node *nhead =removeNthFromEnd(head,3);
    print(nhead);

}