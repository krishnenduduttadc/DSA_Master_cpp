#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Global pointers for the linked list
Node* head = nullptr;
Node* tail = nullptr;
int size = 0;

// Function to add a node at the end of the list
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

// Function to display the elements of the list
void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to get the k-th node from the end
int kthFromLast(int k) {
    Node* slow = head;
    Node* fast = head;

    // Move fast pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            cout << "List size is less than k" << endl;
            return -1;
        }
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

// Function to free memory (destructor equivalent)
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

// Main function
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
