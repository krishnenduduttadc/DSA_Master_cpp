#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int x) {
        val = x;
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

void printListWithRandom(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val << "(" << (curr->random ? to_string(curr->random->val) : "null") << ") ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;       // 1 -> 3
    head->next->random = head;             // 2 -> 1
    head->next->next->random = head->next; // 3 -> 2

    Node* clonedHead = copyRandomList(head);

    cout << "Original List:" << endl;
    printListWithRandom(head);
    cout << "\nCloned List:" << endl;
    printListWithRandom(clonedHead);

    return 0;
}
