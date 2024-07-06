#include <iostream>

using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// LinkedList class definition
class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Method to add a node at the end of the list
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

    // Method to display the elements of the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Method to get the size of the list
    int getSize() {
        return size;
    }

    // Method to find the k-th node from the end
    int kthFromLast(int k) {
        Node* slow = head;
        Node* fast = head;

        // Move fast pointer k steps ahead
        for (int i = 0; i < k; i++) {
            if (fast == nullptr) {
                cout << "List size is less than k" << endl;
                return -1;
            }
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow points to the k-th node from the end
        return slow->data;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

// Main function to demonstrate LinkedList operations
int main() {
    LinkedList list;

    // Adding elements to the list
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    list.addLast(40);
    list.addLast(50);

    // Displaying the original list
    cout << "Original list:" << endl;
    list.display();

    // Getting the value of the k-th node from the end
    int k = 3;
    int kthValue = list.kthFromLast(k);
    if (kthValue != -1) {
        cout << "Value of the " << k << "th node from the end: " << kthValue << endl;
    }

    return 0;
}
