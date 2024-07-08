#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DeletenodeinDoublyLinkedList {
public:
    // Function to delete the node at position x and return the head of the linked list
    Node* deleteNode(Node* head, int x) {
        if (head == nullptr || x <= 0) return head; // If list is empty or position is invalid

        Node* d = head;

        // Traverse to the node at position x
        for (int i = 1; i < x; i++) {
            d = d->next;
            if (d == nullptr) return head; // If position x is out of bounds
        }

        // If the node to be deleted is the head node
        if (d->prev == nullptr) {
            head = d->next;
            if (head != nullptr) head->prev = nullptr;
        }
        // If the node to be deleted is the tail node
        else if (d->next == nullptr) {
            d->prev->next = nullptr;
        }
        // If the node to be deleted is in the middle
        else {
            d->prev->next = d->next;
            d->next->prev = d->prev;
        }

        // Disconnect the deleted node from the list
        d->next = nullptr;
        d->prev = nullptr;
        delete d; // Free memory of the deleted node

        return head;
    }

    // Utility function to print the list from head to tail
    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DeletenodeinDoublyLinkedList sol;

    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original List:" << endl;
    sol.printList(head);

    // Delete node at position 3 (1-based index)
    head = sol.deleteNode(head, 3);
    cout << "List after deleting node at position 3:" << endl;
    sol.printList(head);

    // Delete node at position 1 (head)
    head = sol.deleteNode(head, 1);
    cout << "List after deleting node at position 1:" << endl;
    sol.printList(head);

    // Delete node at position 3 (tail)
    head = sol.deleteNode(head, 3); // Note: current length is 3 after deletions
    cout << "List after deleting node at position 3:" << endl;
    sol.printList(head);

    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
