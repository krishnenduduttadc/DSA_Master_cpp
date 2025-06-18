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

// Linked list helpers
Node* head = nullptr;
Node* tail = nullptr;
int size = 0;

// Add node at end
void addLast(int val) {
    Node* newNode = new Node(val);
    if (size == 0) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

// Display list
void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Get first element
int getFirst() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return -1;
    }
    return head->data;
}

// Get last element
int getLast() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return -1;
    }
    return tail->data;
}

// Get element at index
int getAt(int idx) {
    if (size == 0 || idx < 0 || idx >= size) {
        cout << "Invalid index or list is empty" << endl;
        return -1;
    }
    Node* temp = head;
    for (int i = 0; i < idx; i++) {
        temp = temp->next;
    }
    return temp->data;
}

// Get middle element
int mid() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return -1;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

// Remove first node
void removeFirst() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
    if (size == 0) {
        tail = nullptr;
    }
}

// Free entire list memory
void freeList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

int main() {
    addLast(10);
    display();                          // 10
    cout << getFirst() << endl;         // 10

    addLast(20);
    addLast(30);
    cout << getFirst() << endl;         // 10
    cout << getLast() << endl;          // 30
    cout << getAt(1) << endl;           // 20

    addLast(40);
    cout << mid() << endl;              // 20
    cout << getLast() << endl;          // 40

    addLast(50);
    removeFirst();                      // remove 10
    cout << getFirst() << endl;         // 20

    removeFirst();                      // remove 20
    removeFirst();                      // remove 30
    cout << mid() << endl;              // 40

    removeFirst();                      // remove 40
    removeFirst();                      // remove 50
    cout << getFirst() << endl;         // List is empty

    // Free memory
    freeList();

    return 0;
}
