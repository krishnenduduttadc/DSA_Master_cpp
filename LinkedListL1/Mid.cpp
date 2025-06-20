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
    Node* newNode = new Node(val);
    if (size == 0) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
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

int getFirst() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return -1;
    }
    return head->data;
}

int getLast() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return -1;
    }
    return tail->data;
}

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

    freeList();

    return 0;
}
