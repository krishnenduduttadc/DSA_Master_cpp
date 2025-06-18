#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

Node* flatten(Node* head) {
    if (head == nullptr) return head;

    Node dummy(0);
    dummy.next = head;
    Node* curr = &dummy;
    Node* prev = &dummy;

    stack<Node*> stack;
    stack.push(head);

    while (!stack.empty()) {
        Node* temp = stack.top();
        stack.pop();
        prev->next = temp;
        temp->prev = prev;

        if (temp->next != nullptr) stack.push(temp->next);
        if (temp->child != nullptr) {
            stack.push(temp->child);
            temp->child = nullptr;
        }
        prev = temp;
    }

    dummy.next->prev = nullptr;
    return dummy.next;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->prev = head->next->next->child;
    head->next->next->child->next->child = new Node(11);
    head->next->next->child->next->child->next = new Node(12);

    Node* result = flatten(head);
    printList(result);

    // Free the allocated memory
    Node* curr = result;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}