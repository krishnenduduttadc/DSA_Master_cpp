#include <iostream>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = nullptr;
    }

    // Constructor with data parameter
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
    
    void setNext(Node* next) {
        this->next = next;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

// Function to add two linked lists representing numbers
Node* add(Node* l1, Node* l2, int carry) {
    if (l1 == nullptr && l2 == nullptr && carry == 0) {
        return nullptr;
    }

    Node* result = new Node();
    int value = carry;
    if (l1 != nullptr) {
        value += l1->data;
    }
    if (l2 != nullptr) {
        value += l2->data;
    }
    result->data = value % 10;

    if (l1 != nullptr || l2 != nullptr) {
        Node* more = add(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, value >= 10 ? 1 : 0);
        result->setNext(more);
    }
    return result;
}

int main() {
    // Creating two linked lists representing numbers
    Node* head1 = new Node(7);
    head1->next = new Node(1);
    head1->next->next = new Node(6);

    Node* head2 = new Node(5);
    head2->next = new Node(9);
    head2->next->next = new Node(2);

    // Adding the two linked lists
    Node* result = add(head1, head2, 0);

    // Printing the result linked list
    cout << "Result of addition:" << endl;
    printList(result);

    return 0;
}
