#include <iostream>
#include <unordered_set>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        } else {
            cout << " -> null";
        }
        current = current->next;
    }
    cout << endl;
}

// Function to remove duplicates from the linked list
void deleteDups(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    Node* current = head;
    while (current != nullptr) {
        Node* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                runner->next = runner->next->next;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main() {
    // Creating a linked list with 5 hard-coded nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(5);

    // Print the original linked list
    cout << "Original Linked List:" << endl;
    printList(head);

    // Remove duplicates
    deleteDups(head);

    // Print the linked list after removing duplicates
    cout << "Linked List after removing duplicates:" << endl;
    printList(head);

    return 0;
}
