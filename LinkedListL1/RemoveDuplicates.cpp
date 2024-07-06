#include <iostream>
#include <unordered_set>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// LinkedList class definition
class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

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

    void removeDuplicates() {
        unordered_set<int> seen;
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (seen.find(curr->data) != seen.end()) {
                // Duplicate found, remove the node
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                size--;
            } else {
                // No duplicate found, add current data to set and move pointers
                seen.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        tail = prev;
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    // Hardcoded input
    int elements[] = {2, 2, 2, 3, 3, 5, 5, 5, 5, 5};

    LinkedList l1;
    for (int element : elements) {
        l1.addLast(element);
    }

    cout << "Original List:" << endl;
    l1.display();

    l1.removeDuplicates();

    cout << "List after removing duplicates:" << endl;
    l1.display();

    return 0;
}
