#include <iostream>
#include <unordered_set>
using namespace std;

// Define a node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

// Function to add a node at the end of the list
void addLast(Node*& head, Node*& tail, int& size, int val) {
    Node* newNode = createNode(val);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(Node*& head, Node*& tail, int& size) {
    if (head == nullptr) return;

    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (seen.find(curr->data) != seen.end()) {
            // Duplicate found, remove current node
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            size--;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    tail = prev;
}

// Function to clean up the list and free memory
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    // Hardcoded input
    int elements[] = {2, 2, 2, 3, 3, 5, 5, 5, 5, 5};
    int n = sizeof(elements) / sizeof(elements[0]);

    // Create linked list using struct-based approach
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    for (int i = 0; i < n; ++i) {
        addLast(head, tail, size, elements[i]);
    }

    cout << "Original List:" << endl;
    display(head);

    removeDuplicates(head, tail, size);

    cout << "List after removing duplicates:" << endl;
    display(head);

    deleteList(head);  // Clean up memory

    return 0;
}
