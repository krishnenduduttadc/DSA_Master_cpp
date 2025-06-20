#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

void addLast(Node*& head, Node*& tail, int& size, int val) {
    Node* newNode = createNode(val);
    if (size == 0) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void addFirst(Node*& head, Node*& tail, int& size, int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    if (size == 0) {
        tail = newNode;
    }
    size++;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getFirst(Node* head, int size) {
    if (size == 0) {
        cout << "List is empty" << endl;
        return -1;
    }
    return head->data;
}

void removeFirst(Node*& head, Node*& tail, int& size) {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    } else if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size--;
}

void oddEven(Node*& head, Node*& tail, int& size) {
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    int oddSize = 0;

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    int evenSize = 0;

    while (size > 0) {
        int val = getFirst(head, size);
        removeFirst(head, tail, size);

        if (val % 2 == 0) {
            addLast(evenHead, evenTail, evenSize, val);
        } else {
            addLast(oddHead, oddTail, oddSize, val);
        }
    }

    if (oddSize > 0 && evenSize > 0) {
        oddTail->next = evenHead;
        head = oddHead;
        tail = evenTail;
        size = oddSize + evenSize;
    } else if (oddSize > 0) {
        head = oddHead;
        tail = oddTail;
        size = oddSize;
    } else if (evenSize > 0) {
        head = evenHead;
        tail = evenTail;
        size = evenSize;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    addLast(head, tail, size, 2);
    addLast(head, tail, size, 8);
    addLast(head, tail, size, 9);
    addLast(head, tail, size, 1);
    addLast(head, tail, size, 5);
    addLast(head, tail, size, 4);
    addLast(head, tail, size, 3);

    cout << "Original List: ";
    display(head);

    oddEven(head, tail, size);
    cout << "List after Odd-Even Segregation: ";
    display(head);

    int a = 10, b = 100;
    addFirst(head, tail, size, a);
    addLast(head, tail, size, b);
    cout << "List after adding " << a << " at the beginning and " << b << " at the end: ";
    display(head);

    return 0;
}
