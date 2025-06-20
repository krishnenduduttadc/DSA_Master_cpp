#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

void addLast(Node*& head, Node*& tail, int val) {
    Node* temp = new Node(val);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isPalindrome(Node* head) {
    stack<int> s;
    Node* slow = head;

    while (slow != nullptr) {
        s.push(slow->data);
        slow = slow->next;
    }

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

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    addLast(head, tail, 1);
    addLast(head, tail, 2);
    addLast(head, tail, 3);
    addLast(head, tail, 2);
    addLast(head, tail, 1);

    display(head);
    cout << boolalpha << isPalindrome(head) << endl; // Output: true

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
