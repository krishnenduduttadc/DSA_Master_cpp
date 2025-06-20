#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int x) {
        data = x;
        next = nullptr;
    }
};

ListNode* merge(ListNode* h1, ListNode* h2) {
    if (h1 == nullptr) return h2;
    if (h2 == nullptr) return h1;

    ListNode* ans = nullptr;
    ListNode* t = nullptr;

    if (h1->data < h2->data) {
        ans = h1;
        t = h1;
        h1 = h1->next;
    } else {
        ans = h2;
        t = h2;
        h2 = h2->next;
    }

    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data < h2->data) {
            t->next = h1;
            t = t->next;
            h1 = h1->next;
        } else {
            t->next = h2;
            t = t->next;
            h2 = h2->next;
        }
    }

    if (h1 != nullptr) t->next = h1;
    if (h2 != nullptr) t->next = h2;

    return ans;
}

ListNode* mid(ListNode* h) {
    ListNode* slow = h;
    ListNode* fast = h;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* mergeSort(ListNode* h1) {
    if (h1 == nullptr || h1->next == nullptr) return h1;

    ListNode* m = mid(h1);
    ListNode* h2 = m->next;
    m->next = nullptr;

    ListNode* t1 = mergeSort(h1);
    ListNode* t2 = mergeSort(h2);
    ListNode* t3 = merge(t1, t2);

    return t3;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original Linked List:" << endl;
    printList(head);

    head = mergeSort(head);

    cout << "Sorted Linked List:" << endl;
    printList(head);

    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
