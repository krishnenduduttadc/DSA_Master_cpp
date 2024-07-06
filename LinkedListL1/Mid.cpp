#include <iostream>

using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int d) {
        data = d;
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
        Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
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

    // Method to get the first element of the list
    int getFirst() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return -1; // Return -1 or throw an exception as per your requirement
        } else {
            return head->data;
        }
    }

    // Method to get the last element of the list
    int getLast() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return -1; // Return -1 or throw an exception as per your requirement
        } else {
            return tail->data;
        }
    }

    // Method to get the element at a specified index
    int getAt(int idx) {
        if (size == 0 || idx < 0 || idx >= size) {
            cout << "Invalid index or list is empty" << endl;
            return -1; // Return -1 or throw an exception as per your requirement
        } else {
            Node* temp = head;
            for (int i = 0; i < idx; i++) {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    // Method to find the middle element of the list
    int mid() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return -1; // Return -1 or throw an exception as per your requirement
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    // Method to remove the first element of the list
    void removeFirst() {
        if (size == 0) {
            cout << "List is empty" << endl;
        } else if (size == 1) {
            head = tail = nullptr;
            size = 0;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    // Destructor to free memory
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
    LinkedList list;

    // Adding elements to the list
    list.addLast(10);
    list.display();

    // Demonstrating other operations
    cout << list.getFirst() << endl;

    list.addLast(20);
    list.addLast(30);

    cout << list.getFirst() << endl;
    cout << list.getLast() << endl;
    cout << list.getAt(1) << endl;

    list.addLast(40);

    cout << list.mid() << endl;

    cout << list.getLast() << endl;

    list.addLast(50);
    list.removeFirst();
    cout << list.getFirst() << endl;

    list.removeFirst();
    list.removeFirst();
    cout << list.mid() << endl;

    list.removeFirst();
    list.removeFirst();
    cout << list.getFirst() << endl;

    return 0;
}
