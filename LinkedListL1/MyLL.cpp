#include <iostream>
using namespace std;

// Define the Node class
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

// Define the MyLL class
class MyLL {
public:
    Node* head;  // head of list

    MyLL() {
        head = nullptr;
    }

    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push(int new_data) {
        Node* new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
    }

    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main() {
    MyLL llist;
    llist.push(11);
    llist.push(10);
    llist.push(9);
    llist.push(6);
    llist.push(4);
    llist.push(1);
    llist.push(0);

    cout << "Original Linked List:" << endl;
    llist.printList(llist.head);

    cout << "Reversed Linked List:" << endl;
    llist.head = llist.reverse(llist.head);
    llist.printList(llist.head);

    return 0;
}
