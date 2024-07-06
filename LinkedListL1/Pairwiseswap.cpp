#include <iostream>

using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

// PairwiseSwapLL class definition
class PairwiseSwapLL {
public:
    Node* head;

    PairwiseSwapLL() {
        head = nullptr;
    }

    // Method to print the elements of the list
    void printList(Node* node) {
        while (node != nullptr) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    // Method to perform pairwise swapping of nodes
    Node* pairWiseSwap(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }

        Node* remaining = node->next->next;
        Node* newHead = node->next;
        node->next->next = node;
        node->next = pairWiseSwap(remaining);
        return newHead;
    }
};

int main() {
    // Create an instance of PairwiseSwapLL
    PairwiseSwapLL list;

    // Construct the linked list: 1->2->3->4->5->6->7
    list.head = new Node(1);
    list.head->next = new Node(2);
    list.head->next->next = new Node(3);
    list.head->next->next->next = new Node(4);
    list.head->next->next->next->next = new Node(5);
    list.head->next->next->next->next->next = new Node(6);
    list.head->next->next->next->next->next->next = new Node(7);

    // Display the original list
    cout << "Linked list before calling pairwiseSwap() " << endl;
    list.printList(list.head);

    // Perform pairwise swapping
    list.head = list.pairWiseSwap(list.head);

    // Display the list after pairwise swapping
    cout << "Linked list after calling pairwiseSwap() " << endl;
    list.printList(list.head);

    // Clean up allocated memory
    Node* curr = list.head;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}
