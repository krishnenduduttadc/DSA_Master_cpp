#include <iostream>

using namespace std;

// Node structure definition
struct Node {
    int data;
    Node* next;
};

// Linked list state variables
Node* head = nullptr;
Node* tail = nullptr;
int size = 0;

// Function to create a new node
Node* createNode(int d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;
    return newNode;
}

void addLast(int val) {
    Node* temp = createNode(val);
    if (size == 0) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    size++;
}

int getSize() {
    return size;
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void removeFirst() {
    if (size == 0) {
        cout << "List is empty" << endl;
    } else if (size == 1) {
        head = tail = nullptr;
        size = 0;
    } else {
        head = head->next;
        size--;
    }
}

int getFirst() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return -1;
    } else {
        return head->data;
    }
}

int getLast() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return -1;
    } else {
        return tail->data;
    }
}

int getAt(int idx) {
    if (size == 0) {
        cout << "List is empty" << endl;
        return -1;
    } else if (idx < 0 || idx >= size) {
        cout << "Invalid arguments" << endl;
        return -1;
    } else {
        Node* temp = head;
        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
}

void addFirst(int val) {
    Node* temp = createNode(val);
    temp->next = head;
    head = temp;
    if (size == 0) {
        tail = temp;
    }
    size++;
}

void addAt(int idx, int val) {
    if (idx < 0 || idx > size) {
        cout << "Invalid arguments" << endl;
    } else if (idx == 0) {
        addFirst(val);
    } else if (idx == size) {
        addLast(val);
    } else {
        Node* node = createNode(val);
        Node* temp = head;
        for (int i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;

        size++;
    }
}

// Main function to demonstrate LinkedList operations
int main() {
    // Hardcoded sequence of operations
    addFirst(10);
    cout << getFirst() << endl; // Should display: 10

    addAt(0, 20);
    cout << getFirst() << endl; // Should display: 20
    cout << getLast() << endl;  // Should display: 10

    display(); // Should display: 20 10

    cout << getSize() << endl; // Should display: 2

    addAt(2, 40);
    cout << getLast() << endl; // Should display: 40

    addAt(1, 50);
    addFirst(30);
    removeFirst();
    cout << getFirst() << endl; // Should display: 20

    removeFirst();
    removeFirst();
    addAt(2, 60);
    display(); // Should display: 50 10 60

    cout << getSize() << endl; // Should display: 3

    removeFirst();
    removeFirst();
    cout << getFirst() << endl; // Should display: 60

    return 0;
}
