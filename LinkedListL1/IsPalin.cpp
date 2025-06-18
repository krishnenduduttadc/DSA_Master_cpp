#include <iostream>
#include <stack>

using namespace std;

// Node structure definition
struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

// Function to add a node at the end of the list
void addLast(Node*& head, Node*& tail, int val) {
    Node* temp = new Node(val);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// Function to display the elements of the list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    stack<int> s;
    Node* slow = head;

    // Push all elements to stack
    while (slow != nullptr) {
        s.push(slow->data);
        slow = slow->next;
    }

    // Compare while popping
    slow = head;
    while (slow != nullptr) {
        int top = s.top();
        s.pop();
        if (slow->data != top) {
            return false;
        }
        slow = slow->next;
    }

    return true;
}

// Main function to demonstrate linked list operations
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Add elements
    addLast(head, tail, 1);
    addLast(head, tail, 2);
    addLast(head, tail, 3);
    addLast(head, tail, 2);
    addLast(head, tail, 1);

    // Display and check palindrome
    display(head);
    cout << boolalpha << isPalindrome(head) << endl; // Output: true

    // Cleanup
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
