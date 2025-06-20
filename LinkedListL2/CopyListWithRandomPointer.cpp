#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;

    unordered_map<Node*, Node*> map;
    Node* curr = head;

    while (curr != nullptr) {
        map[curr] = new Node(curr->val);
        curr = curr->next;
    }

    curr = head;
    while (curr != nullptr) {
        map[curr]->next = map[curr->next];
        map[curr]->random = map[curr->random];
        curr = curr->next;
    }

    return map[head];
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << "Node(" << head->val << ")";
        if (head->random != nullptr) {
            cout << " [Random(" << head->random->val << ")]";
        }
        cout << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;
    head->next->random = head;

    Node* result = copyRandomList(head);
    printList(result);

    Node* curr = result;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
