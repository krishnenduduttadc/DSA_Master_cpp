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
int getLength(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *getIntersectionNode(Node *head1, Node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    while(len1>len2){
        head1=head1->next;
        len1--;
    }
    while(len2>len1){
        head2=head2->next;
        len2--;
    }
    
    while(head1!=nullptr && head2!=nullptr){
        if(head1==head2){
            return head1;
        }
        head1=head1->next;
        head2=head2->next;
    }

    return nullptr;
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

    Node* intNode=getIntersectionNode(head1,head2);
    cout<<"Resulting node is :"<<intNode->data;
}