#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

// Global pointers for the linked list
Node* head = nullptr;
Node* tail = nullptr;
int size = 0;

// Function to add a node at the beginning
void addFirst(int val) {
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
    if (size == 0) {
        tail = temp;
    }
    size++;
}

// Function to add a node at the end
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

// Function to display the linked list
void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to remove the first node
void removeFirst() {
    if (size == 0) {
        cout << "List is empty" << endl;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (size == 0) {
            tail = nullptr;
        }
    }
}

// Function to get the first element's data
int getFirst() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return -1;
    }
    return head->data;
}

// Helper function to reverse k nodes (used internally)
void kReverse(int k) {
    Node* newHead = nullptr;
    Node* newTail = nullptr;
    int originalSize = size;

    while (size > 0) {
        int groupSize = (size >= k) ? k : size;
        Node* prev = nullptr;
        Node* curr = head;

        // Reverse 'groupSize' nodes
        for (int i = 0; i < groupSize; i++) {
            Node* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        // Move head forward
        for (int i = 0; i < groupSize; i++) {
            removeFirst();
        }

        // Attach reversed group
        if (newHead == nullptr) {
            newHead = prev;
            newTail = newHead;
            while (newTail->next != nullptr) newTail = newTail->next;
        } else {
            newTail->next = prev;
            while (newTail->next != nullptr) newTail = newTail->next;
        }
    }

    // Restore new head, tail, size
    head = newHead;
    tail = newTail;
    size = originalSize;
}

// Main function
int main() {
    addLast(1);
    addLast(2);
    addLast(3);
    addLast(4);
    addLast(5);
    addLast(6);
    addLast(7);
    addLast(8);
    addLast(9);
    addLast(10);
    addLast(11);

    cout << "Original list: ";
    display();  // 1 2 3 4 5 6 7 8 9 10 11

    int k = 3;
    kReverse(k);

    cout << "After kReverse(" << k << "): ";
    display();  // 3 2 1 6 5 4 9 8 7 10 11

    addFirst(100);
    addLast(200);

    cout << "Final list: ";
    display();  // 100 3 2 1 6 5 4 9 8 7 10 11 200

    return 0;
}
