#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;
int size = 0;

void addLast(int val) {
    Node* temp = new Node(val);
    if (size == 0) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    size++;
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int kthFromLast(int k) {
    Node* slow = head;
    Node* fast = head;

    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            cout << "List size is less than k" << endl;
            return -1;
        }
        fast = fast->next;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

void deleteList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
}

int main() {
    addLast(10);
    addLast(20);
    addLast(30);
    addLast(40);
    addLast(50);

    cout << "Original list:" << endl;
    display();

    int k = 3;
    int kthValue = kthFromLast(k);
    if (kthValue != -1) {
        cout << "Value of the " << k << "th node from the end: " << kthValue << endl;
    }

    deleteList();  // Free memory

    return 0;
}
