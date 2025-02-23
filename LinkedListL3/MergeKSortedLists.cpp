#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

Node* mergeKLists(std::vector<Node*>& lists) {
    if (lists.empty()) return nullptr;

    auto compare = [](Node* a, Node* b) { return a->val > b->val; };
    std::priority_queue<Node*, std::vector<Node*>, decltype(compare)> queue(compare);

    Node dummy(0);
    Node* tail = &dummy;

    for (Node* node : lists) {
        if (node != nullptr) queue.push(node);
    }
    
    while (!queue.empty()) {
        tail->next = queue.top();
        queue.pop();
        tail = tail->next;

        if (tail->next != nullptr) queue.push(tail->next);
    }

    return dummy.next;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

int main() {
    std::vector<Node*> lists(3);
    lists[0] = new Node(1);
    lists[0]->next = new Node(4);
    lists[0]->next->next = new Node(5);

    lists[1] = new Node(1);
    lists[1]->next = new Node(3);
    lists[1]->next->next = new Node(4);

    lists[2] = new Node(2);
    lists[2]->next = new Node(6);

    Node* result = mergeKLists(lists);
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
